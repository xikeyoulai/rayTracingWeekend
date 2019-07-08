#include "pch.h"
#include "image.h"
#include <iostream>
#include "svpng.inc"

using namespace std;

image::image()
{
}

void image::createImage() 
{
	int nx = 200;
	int ny = 100;
	cout << "P3\n" << nx << " " << ny << "\n255\n";
	for (int j = ny - 1; j >= 0; j--) {
		for (int i = 0; i < nx; i++) {
			float r = float(i) / float(nx);
			float g = float(j) / float(ny);
			float b = 0.2;
			int ir = int(255.99 * r);
			int ig = int(255.99 * g);
			int ib = int(255.99 * b);
			cout << ir << " " << ig << " " << ib << " " << "\n";
		}
	}
}

void image::createRGBPng()
{
	unsigned char rgb[256 * 256 * 3], *p = rgb;
	unsigned x, y;
	FILE *fp = fopen("rgb.png", "wb");
	for (y = 0; y < 256; y++)
		for (x = 0; x < 256; x++) {
			*p++ = (unsigned char)x;    /* R */
			*p++ = (unsigned char)y;    /* G */
			*p++ = 128;                 /* B */
		}
	svpng(fp, 256, 256, rgb, 0);
	fclose(fp);
}

void image::createRGBAPng()
{
	unsigned char rgba[256 * 256 * 4], *p = rgba;
	unsigned x, y;
	FILE* fp = fopen("rgba.png", "wb");
	for (y = 0; y < 256; y++)
		for (x = 0; x < 256; x++) {
			*p++ = (unsigned char)x;                /* R */
			*p++ = (unsigned char)y;                /* G */
			*p++ = 128;                             /* B */
			*p++ = (unsigned char)((x + y) / 2);    /* A */
		}
	svpng(fp, 256, 256, rgba, 1);
	fclose(fp);
}


image::~image()
{
}

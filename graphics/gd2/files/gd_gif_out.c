#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "gd.h"

/*
** Wrapper functions for GIF output.
*/

#define LZW_LICENCED

void gdImageGifToSink(gdImagePtr im, gdSinkPtr outSink)
{
        gdIOCtx   *out = gdNewSSCtx(NULL,outSink);
        gdImageGifCtx(im, out);
        out->free(out);
}

void gdImageGifCtx(gdImagePtr im, gdIOCtx *out)
{
#ifdef LZW_LICENCED
	gdImageLzwCtx(im, out);
#else
        gdImageBigGifCtx(im, out);
#endif
}

void gdImageGif(gdImagePtr im, FILE *outFile)
{
#ifdef LZW_LICENCED
        gdImageLzw(im, outFile);
#else
        gdImageBigGif(im, outFile);
#endif
}

void* gdImageGifPtr(gdImagePtr im, int *size)
{
#ifdef LZW_LICENCED
        return gdImageLzwPtr(im, size);
#else
        return gdImageBigGifPtr(im, size);
#endif
}


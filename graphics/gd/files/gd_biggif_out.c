#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "gd.h"

/*
** Wrapper functions for this module.
*/

void gdImageBigGif(gdImagePtr im, FILE *outFile)
{
        gdIOCtx   *out = gdNewFileCtx(outFile);
        gdImageBigGifCtx(im, out);
	out->gd_free(out);
}

void* gdImageBigGifPtr(gdImagePtr im, int *size)
{
	void	*rv;
        gdIOCtx   *out = gdNewDynamicCtx(2048, NULL);
        gdImageBigGifCtx(im, out);
	rv = gdDPExtractData(out,size);
 	out->gd_free(out);
	return rv;
}

/* Code drawn from ppmtogif.c, from the pbmplus package
**
** Based on GIFENCOD by David Rowley <mgardi@watdscu.waterloo.edu>. A
** Lempel-Zim compression based on "compress".
**
** Modified by Marcel Wijkstra <wijkstra@fwi.uva.nl>
**
** Copyright (C) 1989 by Jef Poskanzer.
**
** Permission to use, copy, modify, and distribute this software and its
** documentation for any purpose and without fee is hereby granted, provided
** that the above copyright notice appear in all copies and that both that
** copyright notice and this permission notice appear in supporting
** documentation.  This software is provided "as is" without express or
** implied warranty.
**
** The Graphics Interchange Format(c) is the Copyright property of
** CompuServe Incorporated.  GIF(sm) is a Service Mark property of
** CompuServe Incorporated.
*
*  Heavily modified by Mouse, 1998-02-12.  
*  Remove LZW compression.
*  Added miGIF run length compression.
*
*/

/*
 * a code_int must be able to hold 2**GIFBITS values of type int, and also -1
 */
typedef int code_int;

static int colorstobpp(int colors);
static void BumpPixel (void);
static int GIFNextPixel (gdImagePtr im);
static void GIFEncode (gdIOCtx *fp, int GWidth, int GHeight, int GInterlace, int Background, int Transparent, int BitsPerPixel, int *Red, int *Green, int *Blue, gdImagePtr im);
/*static void Putword (int w, gdIOCtx *fp); */
static void GIFcompress (int, gdIOCtx *, gdImagePtr, int);
static void output (code_int code);

/* UNUSED
* static void char_init (void);
* static void char_out (int c);
*/

/* Allows for reuse */
static void init_statics(void);

void gdImageBigGifCtx(gdImagePtr im, gdIOCtx *out)
{
	int interlace, transparent, BitsPerPixel;

	interlace = im->interlace;
	transparent = im->transparent;

	BitsPerPixel = colorstobpp(im->colorsTotal);
	/* Clear any old values in statics strewn through the GIF code */
	init_statics();
	/* All set, let's do it. */
	GIFEncode(
		out, im->sx, im->sy, interlace, 0, transparent, BitsPerPixel,
		im->red, im->green, im->blue, im);
}

static int
colorstobpp(int colors)
{
    int bpp = 0;

    if ( colors <= 2 )
        bpp = 1;
    else if ( colors <= 4 )
        bpp = 2;
    else if ( colors <= 8 )
        bpp = 3;
    else if ( colors <= 16 )
        bpp = 4;
    else if ( colors <= 32 )
        bpp = 5;
    else if ( colors <= 64 )
        bpp = 6;
    else if ( colors <= 128 )
        bpp = 7;
    else if ( colors <= 256 )
        bpp = 8;
    return bpp;
    }

/*****************************************************************************
 *
 * GIFENCODE.C    - GIF Image compression interface
 *
 * GIFEncode( FName, GHeight, GWidth, GInterlace, Background, Transparent,
 *            BitsPerPixel, Red, Green, Blue, gdImagePtr )
 *
 *****************************************************************************/

#define TRUE 1
#define FALSE 0

static int Width, Height;
static int curx, cury;
static long CountDown;
static int Pass = 0;
static int Interlace;

/*
 * Bump the 'curx' and 'cury' to point to the next pixel
 */
static void
BumpPixel(void)
{
        /*
         * Bump the current X position
         */
        ++curx;

        /*
         * If we are at the end of a scan line, set curx back to the beginning
         * If we are interlaced, bump the cury to the appropriate spot,
         * otherwise, just increment it.
         */
        if( curx == Width ) {
                curx = 0;

                if( !Interlace )
                        ++cury;
                else {
                     switch( Pass ) {

                       case 0:
                          cury += 8;
                          if( cury >= Height ) {
                                ++Pass;
                                cury = 4;
                          }
                          break;

                       case 1:
                          cury += 8;
                          if( cury >= Height ) {
                                ++Pass;
                                cury = 2;
                          }
                          break;

                       case 2:
                          cury += 4;
                          if( cury >= Height ) {
                             ++Pass;
                             cury = 1;
                          }
                          break;

                       case 3:
                          cury += 2;
                          break;
                        }
                }
        }
}

/*
 * Return the next pixel from the image
 */
static int
GIFNextPixel(gdImagePtr im)
{
        int r;

        if( CountDown == 0 )
                return EOF;

        --CountDown;

        r = gdImageGetPixel(im, curx, cury);

        BumpPixel();

        return r;
}

/* public */

static void
GIFEncode(gdIOCtx *fp, int GWidth, int GHeight, int GInterlace, int Background, int Transparent, int BitsPerPixel, int *Red, int *Green, int *Blue, gdImagePtr im)
{
        int B;
        int RWidth, RHeight;
        int LeftOfs, TopOfs;
        int Resolution;
        int ColorMapSize;
        int InitCodeSize;
        int i;

        Interlace = GInterlace;

        ColorMapSize = 1 << BitsPerPixel;

        RWidth = Width = GWidth;
        RHeight = Height = GHeight;
        LeftOfs = TopOfs = 0;

        Resolution = BitsPerPixel;

        /*
         * Calculate number of bits we are expecting
         */
        CountDown = (long)Width * (long)Height;

        /*
         * Indicate which pass we are on (if interlace)
         */
        Pass = 0;

        /*
         * The initial code size
         */
        if( BitsPerPixel <= 1 )
                InitCodeSize = 2;
        else
                InitCodeSize = BitsPerPixel;

        /*
         * Set up the current x and y position
         */
        curx = cury = 0;

        /*
         * Write the Magic header
         */
        gdPutBuf( Transparent < 0 ? "GIF87a" : "GIF89a", 6, fp );

        /*
         * Write out the screen width and height
         */
        Putword( RWidth, fp );
        Putword( RHeight, fp );

        /*
         * Indicate that there is a global colour map
         */
        B = 0x80;       /* Yes, there is a color map */

        /*
         * OR in the resolution
         */
        B |= (Resolution - 1) << 4;

        /*
         * OR in the Bits per Pixel
         */
        B |= (BitsPerPixel - 1);

        /*
         * Write it out
         */
        gdPutC( B, fp );

        /*
         * Write out the Background colour
         */
        gdPutC( Background, fp );

        /*
         * Byte of 0's (future expansion)
         */
        gdPutC( 0, fp );

        /*
         * Write out the Global Colour Map
         */
        for( i=0; i<ColorMapSize; ++i ) {
                gdPutC( Red[i], fp );
                gdPutC( Green[i], fp );
                gdPutC( Blue[i], fp );
        }

	/*
	 * Write out extension for transparent colour index, if necessary.
	 */
	if ( Transparent >= 0 ) {
	    gdPutC( '!', fp );
	    gdPutC( 0xf9, fp );
	    gdPutC( 4, fp );
	    gdPutC( 1, fp );
	    gdPutC( 0, fp );
	    gdPutC( 0, fp );
	    gdPutC( (unsigned char) Transparent, fp );
	    gdPutC( 0, fp );
	}

        /*
         * Write an Image separator
         */
        gdPutC( ',', fp );

        /*
         * Write the Image header
         */

        Putword( LeftOfs, fp );
        Putword( TopOfs, fp );
        Putword( Width, fp );
        Putword( Height, fp );

        /*
         * Write out whether or not the image is interlaced
         */
        if( Interlace )
                gdPutC( 0x40, fp );
        else
                gdPutC( 0x00, fp );

        /*
         * Write out the initial code size
         */
        gdPutC( InitCodeSize, fp );

        /*
         * Go and actually compress the data
         */
        GIFcompress( InitCodeSize+1, fp, im, Background );

        /*
         * Write out a Zero-length packet (to end the series)
         */
        gdPutC( 0, fp );

        /*
         * Write the GIF file terminator
         */
        gdPutC( ';', fp );
}

/* Write out a word to the GIF file */
/*static void */
/*Putword(int w, gdIOCtx *fp) */
/*{ */
/*        fputc( w & 0xff, fp ); */
/*        fputc( (w / 256) & 0xff, fp ); */
/*} */

#define GIFBITS 12

/*-----------------------------------------------------------------------
 *
 * miGIF Compression - mouse and ivo's GIF-compatible compression
 *
 *          -run length encoding compression routines-
 *
 * Copyright (C) 1998 Hutchison Avenue Software Corporation
 *               http://www.hasc.com
 *               info@hasc.com
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose and without fee is hereby granted, provided
 * that the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation.  This software is provided "AS IS." The Hutchison Avenue 
 * Software Corporation disclaims all warranties, either express or implied, 
 * including but not limited to implied warranties of merchantability and 
 * fitness for a particular purpose, with respect to this code and accompanying
 * documentation. 
 * 
 * The miGIF compression routines do not, strictly speaking, generate files 
 * conforming to the GIF spec, since the image data is not LZW-compressed 
 * (this is the point: in order to avoid transgression of the Unisys patent 
 * on the LZW algorithm.)  However, miGIF generates data streams that any 
 * reasonably sane LZW decompresser will decompress to what we want.
 *
 * miGIF compression uses run length encoding. It compresses horizontal runs 
 * of pixels of the same color. This type of compression gives good results
 * on images with many runs, for example images with lines, text and solid 
 * shapes on a solid-colored background. It gives little or no compression 
 * on images with few runs, for example digital or scanned photos.
 *
 *                               der Mouse
 *                      mouse@rodents.montreal.qc.ca
 *            7D C8 61 52 5D E7 2D 39  4E F1 31 3E E8 B3 27 4B
 *
 *                             ivo@hasc.com
 *
 * The Graphics Interchange Format(c) is the Copyright property of
 * CompuServe Incorporated.  GIF(sm) is a Service Mark property of
 * CompuServe Incorporated.
 *
 */

static int rl_pixel;
static int rl_basecode;
static int rl_count;
static int rl_table_pixel;
static int rl_table_max;
static int just_cleared;
static int out_bits;
static int out_bits_init;
static int out_count;
static int out_bump;
static int out_bump_init;
static int out_clear;
static int out_clear_init;
static int max_ocodes;
static int code_clear;
static int code_eof;
static unsigned int obuf;
static int obits;
static gdIOCtx *ofile;
static unsigned char oblock[256];
static int oblen;

/* Used only when debugging GIF compression code */
/* #define DEBUGGING_ENVARS */

#ifdef DEBUGGING_ENVARS

static int verbose_set = 0;
static int verbose;
#define VERBOSE (verbose_set?verbose:set_verbose())

static int set_verbose(void)
{
 verbose = !!getenv("GIF_VERBOSE");
 verbose_set = 1;
 return(verbose);
}

#else

#define VERBOSE 0

#endif


static const char *binformat(unsigned int v, int nbits)
{
 static char bufs[8][64];
 static int bhand = 0;
 unsigned int bit;
 int bno;
 char *bp;

 bhand --;
 if (bhand < 0) bhand = (sizeof(bufs)/sizeof(bufs[0]))-1;
 bp = &bufs[bhand][0];
 for (bno=nbits-1,bit=1U<<bno;bno>=0;bno--,bit>>=1)
  { *bp++ = (v & bit) ? '1' : '0';
    if (((bno&3) == 0) && (bno != 0)) *bp++ = '.';
  }
 *bp = '\0';
 return(&bufs[bhand][0]);
}

static void write_block(void)
{
 int i;

 if (VERBOSE)
  { printf("write_block %d:",oblen);
    for (i=0;i<oblen;i++) printf(" %02x",oblock[i]);
    printf("\n");
  }
 gdPutC(oblen,ofile);
 gdPutBuf(&oblock[0],oblen,ofile);
 oblen = 0;
}

static void block_out(unsigned char c)
{
 if (VERBOSE) printf("block_out %s\n",binformat(c,8));
 oblock[oblen++] = c;
 if (oblen >= 255) write_block();
}

static void block_flush(void)
{
 if (VERBOSE) printf("block_flush\n");
 if (oblen > 0) write_block();
}

static void output(int val)
{
 if (VERBOSE) printf("output %s [%s %d %d]\n",binformat(val,out_bits),binformat(obuf,obits),obits,out_bits);
 obuf |= val << obits;
 obits += out_bits;
 while (obits >= 8)
  { block_out(obuf&0xff);
    obuf >>= 8;
    obits -= 8;
  }
 if (VERBOSE) printf("output leaving [%s %d]\n",binformat(obuf,obits),obits);
}

static void output_flush(void)
{
 if (VERBOSE) printf("output_flush\n");
 if (obits > 0) block_out(obuf);
 block_flush();
}

static void did_clear(void)
{
 if (VERBOSE) printf("did_clear\n");
 out_bits = out_bits_init;
 out_bump = out_bump_init;
 out_clear = out_clear_init;
 out_count = 0;
 rl_table_max = 0;
 just_cleared = 1;
}

static void output_plain(int c)
{
 if (VERBOSE) printf("output_plain %s\n",binformat(c,out_bits));
 just_cleared = 0;
 output(c);
 out_count ++;
 if (out_count >= out_bump)
  { out_bits ++;
    out_bump += 1 << (out_bits - 1);
  }
 if (out_count >= out_clear)
  { output(code_clear);
    did_clear();
  }
}

static unsigned int isqrt(unsigned int x)
{
 unsigned int r;
 unsigned int v;

 if (x < 2) return(x);
 for (v=x,r=1;v;v>>=2,r<<=1) ;
 while (1)
  { v = ((x / r) + r) / 2;
    if ((v == r) || (v == r+1)) return(r);
    r = v;
  }
}

static unsigned int compute_triangle_count(unsigned int count, unsigned int nrepcodes)
{
 unsigned int perrep;
 unsigned int cost;

 cost = 0;
 perrep = (nrepcodes * (nrepcodes+1)) / 2;
 while (count >= perrep)
  { cost += nrepcodes;
    count -= perrep;
  }
 if (count > 0)
  { unsigned int n;
    n = isqrt(count);
    while ((n*(n+1)) >= 2*count) n --;
    while ((n*(n+1)) < 2*count) n ++;
    cost += n;
  }
 return(cost);
}

static void max_out_clear(void)
{
 out_clear = max_ocodes;
}

static void reset_out_clear(void)
{
 out_clear = out_clear_init;
 if (out_count >= out_clear)
  { output(code_clear);
    did_clear();
  }
}

static void rl_flush_fromclear(int count)
{
 int n;

 if (VERBOSE) printf("rl_flush_fromclear %d\n",count);
 max_out_clear();
 rl_table_pixel = rl_pixel;
 n = 1;
 while (count > 0)
  { if (n == 1)
     { rl_table_max = 1;
       output_plain(rl_pixel);
       count --;
     }
    else if (count >= n)
     { rl_table_max = n;
       output_plain(rl_basecode+n-2);
       count -= n;
     }
    else if (count == 1)
     { rl_table_max ++;
       output_plain(rl_pixel);
       count = 0;
     }
    else
     { rl_table_max ++;
       output_plain(rl_basecode+count-2);
       count = 0;
     }
    if (out_count == 0) n = 1; else n ++;
  }
 reset_out_clear();
 if (VERBOSE) printf("rl_flush_fromclear leaving table_max=%d\n",rl_table_max);
}

static void rl_flush_clearorrep(int count)
{
 int withclr;

 if (VERBOSE) printf("rl_flush_clearorrep %d\n",count);
 withclr = 1 + compute_triangle_count(count,max_ocodes);
 if (withclr < count)
  { output(code_clear);
    did_clear();
    rl_flush_fromclear(count);
  }
 else
  { for (;count>0;count--) output_plain(rl_pixel);
  }
}

static void rl_flush_withtable(int count)
{
 int repmax;
 int repleft;
 int leftover;

 if (VERBOSE) printf("rl_flush_withtable %d\n",count);
 repmax = count / rl_table_max;
 leftover = count % rl_table_max;
 repleft = (leftover ? 1 : 0);
 if (out_count+repmax+repleft > max_ocodes)
  { repmax = max_ocodes - out_count;
    leftover = count - (repmax * rl_table_max);
    repleft = 1 + compute_triangle_count(leftover,max_ocodes);
  }
 if (VERBOSE) printf("rl_flush_withtable repmax=%d leftover=%d repleft=%d\n",repmax,leftover,repleft);
 if (1+compute_triangle_count(count,max_ocodes) < repmax+repleft)
  { output(code_clear);
    did_clear();
    rl_flush_fromclear(count);
    return;
  }
 max_out_clear();
 for (;repmax>0;repmax--) output_plain(rl_basecode+rl_table_max-2);
 if (leftover)
  { if (just_cleared)
     { rl_flush_fromclear(leftover);
     }
    else if (leftover == 1)
     { output_plain(rl_pixel);
     }
    else
     { output_plain(rl_basecode+leftover-2);
     }
  }
 reset_out_clear();
}

static void rl_flush(void)
{
 /* UNUSED int table_reps; */
 /* UNUSED int table_extra; */

 if (VERBOSE) printf("rl_flush [ %d %d\n",rl_count,rl_pixel);
 if (rl_count == 1)
  { output_plain(rl_pixel);
    rl_count = 0;
    if (VERBOSE) printf("rl_flush ]\n");
    return;
  }
 if (just_cleared)
  { rl_flush_fromclear(rl_count);
  }
 else if ((rl_table_max < 2) || (rl_table_pixel != rl_pixel))
  { rl_flush_clearorrep(rl_count);
  }
 else
  { rl_flush_withtable(rl_count);
  }
 if (VERBOSE) printf("rl_flush ]\n");
 rl_count = 0;
}

static void GIFcompress(int init_bits, gdIOCtx *outfile, gdImagePtr im, int background)
{
 int c;

 ofile = outfile;
 obuf = 0;
 obits = 0;
 oblen = 0;
 code_clear = 1 << (init_bits - 1);
 code_eof = code_clear + 1;
 rl_basecode = code_eof + 1;
 out_bump_init = (1 << (init_bits - 1)) - 1;
 /* for images with a lot of runs, making out_clear_init larger will
    give better compression. */ 
 out_clear_init = (init_bits <= 3) ? 9 : (out_bump_init-1);
#ifdef DEBUGGING_ENVARS
  { const char *ocienv;
    ocienv = getenv("GIF_OUT_CLEAR_INIT");
    if (ocienv)
     { out_clear_init = atoi(ocienv);
       if (VERBOSE) printf("[overriding out_clear_init to %d]\n",out_clear_init);
     }
  }
#endif
 out_bits_init = init_bits;
 max_ocodes = (1 << GIFBITS) - ((1 << (out_bits_init - 1)) + 3);
 did_clear();
 output(code_clear);
 rl_count = 0;
 while (1)
  { c = GIFNextPixel(im);
    if ((rl_count > 0) && (c != rl_pixel)) rl_flush();
    if (c == EOF) break;
    if (rl_pixel == c)
     { rl_count ++;
     }
    else
     { rl_pixel = c;
       rl_count = 1;
     }
  }
 output(code_eof);
 output_flush();
}

/*-----------------------------------------------------------------------
 *
 * End of miGIF section  - See copyright notice at start of section.
 *
 *-----------------------------------------------------------------------
*/

/******************************************************************************
 *
 * GIF Specific routines
 *
 ******************************************************************************/

/*
 * Number of characters so far in this 'packet'
 */
static int a_count;

/*
 * Set up the 'byte output' routine
 */

/* UNUSED
* static void
* char_init(void)
* {
*        a_count = 0;
* }
*/

/*
 * Define the storage for the packet accumulator
 */

/* UNUSED static char accum[ 256 ]; */

static void init_statics(void) {
	/* Some of these are properly initialized later. What I'm doing
		here is making sure code that depends on C's initialization
		of statics doesn't break when the code gets called more
		than once. */
	Width = 0;
	Height = 0;
	curx = 0;
	cury = 0;
	CountDown = 0;
	Pass = 0;
	Interlace = 0;
	a_count = 0;
}


/* +-------------------------------------------------------------------+ */
/* | Copyright 1990, 1991, 1993, David Koblas.  (koblas@netcom.com)    | */
/* |   Permission to use, copy, modify, and distribute this software   | */
/* |   and its documentation for any purpose and without fee is hereby | */
/* |   granted, provided that the above copyright notice appear in all | */
/* |   copies and that both that copyright notice and this permission  | */
/* |   notice appear in supporting documentation.  This software is    | */
/* |   provided "as is" without express or implied warranty.           | */
/* +-------------------------------------------------------------------+ */


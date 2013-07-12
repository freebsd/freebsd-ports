--- lib-src/enigma-core/IMG_SavePNG.c.orig	2007-09-08 14:20:05.000000000 +0200
+++ lib-src/enigma-core/IMG_SavePNG.c	2012-05-11 17:55:39.000000000 +0200
@@ -1,13 +1,14 @@
 #include "SDL.h"
 #include "IMG_SavePNG.h"
 #include "png.h"
+#include "pngpriv.h"
 #include <stdlib.h>
 #include <setjmp.h>
 
 #define IMG_SetError(a) SDL_SetError(a)
 
 /* Save a PNG type image to an SDL datasource */
-static void png_write_data(png_structp ctx, png_bytep area, png_size_t size)
+static void local_png_write_data(png_structp ctx, png_bytep area, png_size_t size)
 {
 	SDL_RWops *src;
 	
@@ -84,12 +85,12 @@
                 png_bytep *row_pointers = 0;
 
                 /* Set error handling. */
-                if (setjmp(png_ptr->jmpbuf)) {
+                if (setjmp(png_ptr->longjmp_buffer)) {
                     IMG_SetError("Error writing the PNG file");
                 }
                 else {
 					int colortype;
-                    png_set_write_fn(png_ptr, src, png_write_data, png_io_flush);
+                    png_set_write_fn(png_ptr, src, local_png_write_data, png_io_flush);
                     /* Set the image information here.  Width and height are up to 2^31,
                      * bit_depth is one of 1, 2, 4, 8, or 16, but valid values also depend on
                      * the color_type selected. color_type is one of PNG_COLOR_TYPE_GRAY,

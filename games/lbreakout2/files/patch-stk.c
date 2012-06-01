--- gui/stk.c.orig	2005-03-28 19:18:42.000000000 +0200
+++ gui/stk.c	2012-05-03 07:07:35.000000000 +0200
@@ -19,6 +19,7 @@
 #include <stdarg.h>
 #include <stdlib.h>
 #include <png.h>
+#include <pngpriv.h>
 #include "stk.h"
 
 //#define STK_DEBUG
@@ -54,7 +55,7 @@
 
 /* Load a PNG type image from an SDL datasource */
 #define IMG_SetError	SDL_SetError
-static void png_read_data(png_structp ctx, png_bytep area, png_size_t size)
+static void local_png_read_data(png_structp ctx, png_bytep area, png_size_t size)
 {
 	SDL_RWops *src;
 
@@ -105,13 +106,13 @@
 	 * the normal method of doing things with libpng).  REQUIRED unless you
 	 * set up your own error handlers in png_create_read_struct() earlier.
 	 */
-	if ( setjmp(png_ptr->jmpbuf) ) {
+	if ( setjmp(png_jmpbuf(png_ptr)) ) {
 		IMG_SetError("Error reading the PNG file.");
 		goto done;
 	}
 
 	/* Set up the input control */
-	png_set_read_fn(png_ptr, src, png_read_data);
+	png_set_read_fn(png_ptr, src, local_png_read_data);
 
 	/* Read PNG header info */
 	png_read_info(png_ptr, info_ptr);

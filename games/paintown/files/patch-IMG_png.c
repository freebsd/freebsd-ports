--- src/util/sdl/image/IMG_png.c.orig	2012-04-29 06:46:37.000000000 +0200
+++ src/util/sdl/image/IMG_png.c	2012-04-30 06:37:36.000000000 +0200
@@ -70,6 +70,7 @@
 #define MACOS
 #endif
 #include <png.h>
+#include <pngpriv.h>
 
 
 static struct {
@@ -288,7 +289,7 @@
 }
 
 /* Load a PNG type image from an SDL datasource */
-static void png_read_data(png_structp ctx, png_bytep area, png_size_t size)
+static void local_png_read_data(png_structp ctx, png_bytep area, png_size_t size)
 {
 	SDL_RWops *src;
 
@@ -347,13 +348,13 @@
 	 * the normal method of doing things with libpng).  REQUIRED unless you
 	 * set up your own error handlers in png_create_read_struct() earlier.
 	 */
-	if ( setjmp(png_ptr->jmpbuf) ) {
+	if ( setjmp(png_jmpbuf(png_ptr)) ) {
 		error = "Error reading the PNG file.";
 		goto done;
 	}
 
 	/* Set up the input control */
-	lib.png_set_read_fn(png_ptr, src, png_read_data);
+	lib.png_set_read_fn(png_ptr, src, local_png_read_data);
 
 	/* Read PNG header info */
 	lib.png_read_info(png_ptr, info_ptr);

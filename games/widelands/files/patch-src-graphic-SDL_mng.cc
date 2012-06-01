--- src/graphic/SDL_mng.cc.orig	2011-04-15 20:40:26.000000000 +0200
+++ src/graphic/SDL_mng.cc	2012-05-03 23:15:20.000000000 +0200
@@ -26,6 +26,7 @@
 #include <SDL_endian.h>
 
 #include <png.h>
+#include <pngpriv.h>
 
 /* Chunk structure */
 struct chunk_t {
@@ -230,7 +231,7 @@
 }
 
 /* png_read_data callback; return <size> bytes from wherever */
-static void png_read_data(png_structp ctx, png_bytep area, png_size_t size)
+static void local_png_read_data(png_structp ctx, png_bytep area, png_size_t size)
 {
 	SDL_RWread(static_cast<SDL_RWops *>(png_get_io_ptr(ctx)), area, size, 1);
 }
@@ -276,13 +277,13 @@
 	 * the normal method of doing things with libpng).  REQUIRED unless you
 	 * set up your own error handlers in png_create_read_struct() earlier.
 	 */
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_jmpbuf(png_ptr))) {
 		SDL_SetError("Error reading the PNG file.");
 		goto done;
 	}
 
 	/* Set up the input control */
-	png_set_read_fn(png_ptr, src, png_read_data);
+	png_set_read_fn(png_ptr, src, local_png_read_data);
 
 	/* tell PNG not to read the signature */
 	png_set_sig_bytes(png_ptr, 8);

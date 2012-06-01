--- png.c.orig	2002-11-08 11:50:29.000000000 +0100
+++ png.c	2012-04-30 06:40:16.000000000 +0200
@@ -10,9 +10,10 @@
 #define MACOS
 #endif
 #include <png.h>
+#include <pngpriv.h>
 
 /* png code */
-static void png_read_data(png_structp ctx, png_bytep area, png_size_t size)
+static void local_png_read_data(png_structp ctx, png_bytep area, png_size_t size)
 {
   SDL_RWops *src;
 
@@ -74,13 +75,13 @@
    * the normal method of doing things with libpng).  REQUIRED unless you
    * set up your own error handlers in png_create_read_struct() earlier.
    */
-  if (setjmp(png_ptr->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png_ptr))) {
     SDL_SetError("Error reading the PNG file.");
     goto done;
   }
 
   /* Set up the input control */
-  png_set_read_fn(png_ptr, src, png_read_data);
+  png_set_read_fn(png_ptr, src, local_png_read_data);
 
   /* Read PNG header info */
   png_read_info(png_ptr, info_ptr);

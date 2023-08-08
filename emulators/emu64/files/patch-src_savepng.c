--- src/savepng.c.orig	2023-06-27 17:17:48 UTC
+++ src/savepng.c
@@ -25,7 +25,7 @@
 #endif
 
 /* libpng callbacks */ 
-static void png_error_SDL(png_structp *png_ptr, png_const_charp str)
+static void png_error_SDL(png_structp png_ptr, png_const_charp str)
 {
 	SDL_SetError("libpng: %s\n", str);
 }

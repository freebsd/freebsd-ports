--- src/util/sdl/image/IMG_savepng.c.orig	2012-04-29 06:46:37.000000000 +0200
+++ src/util/sdl/image/IMG_savepng.c	2012-05-01 10:22:57.000000000 +0200
@@ -33,6 +33,7 @@
 #include <SDL/SDL_byteorder.h>
 #endif
 #include <png.h>
+#include <zlib.h>
 #include "IMG_savepng.h"
 
 int IMG_SavePNG(const char *file, SDL_Surface *surf,int compression){
@@ -50,7 +52,7 @@
 	return ret;
 }
 
-static void png_write_data(png_structp png_ptr,png_bytep data, png_size_t length){
+static void local_png_write_data(png_structp png_ptr,png_bytep data, png_size_t length){
 	SDL_RWops *rp = (SDL_RWops*) png_get_io_ptr(png_ptr);
 	SDL_RWwrite(rp,data,1,length);
 }
@@ -89,7 +90,7 @@
 		goto savedone;
 	}
 	/* setup custom writer functions */
-	png_set_write_fn(png_ptr,(voidp)src,png_write_data,NULL);
+	png_set_write_fn(png_ptr,(voidp)src,local_png_write_data,NULL);
 
 	if (setjmp(png_jmpbuf(png_ptr))){
 		SDL_SetError("Unknown error writing PNG");

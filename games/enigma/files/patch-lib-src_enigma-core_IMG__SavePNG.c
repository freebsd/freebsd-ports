--- lib-src/enigma-core/IMG_SavePNG.c.orig	2007-09-08 12:20:05 UTC
+++ lib-src/enigma-core/IMG_SavePNG.c
@@ -7,7 +7,7 @@
 #define IMG_SetError(a) SDL_SetError(a)
 
 /* Save a PNG type image to an SDL datasource */
-static void png_write_data(png_structp ctx, png_bytep area, png_size_t size)
+static void local_png_write_data(png_structp ctx, png_bytep area, png_size_t size)
 {
 	SDL_RWops *src;
 	
@@ -84,12 +84,12 @@ int IMG_SavePNG_RW(SDL_Surface *face, SD
                 png_bytep *row_pointers = 0;
 
                 /* Set error handling. */
-                if (setjmp(png_ptr->jmpbuf)) {
+                if (setjmp(png_jmpbuf(png_ptr))) {
                     IMG_SetError("Error writing the PNG file");
                 }
                 else {
 					int colortype;
-                    png_set_write_fn(png_ptr, src, png_write_data, png_io_flush);
+                    png_set_write_fn(png_ptr, src, local_png_write_data, png_io_flush);
                     /* Set the image information here.  Width and height are up to 2^31,
                      * bit_depth is one of 1, 2, 4, 8, or 16, but valid values also depend on
                      * the color_type selected. color_type is one of PNG_COLOR_TYPE_GRAY,

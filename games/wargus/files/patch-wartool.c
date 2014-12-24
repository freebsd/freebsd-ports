--- wartool.orig.c
+++ wartool.c
@@ -61,6 +61,7 @@
 #include <unistd.h>
 #endif
 #include <ctype.h>
+#include <zlib.h>
 #include <png.h>
 
 #include "endian.h"
@@ -1876,7 +1877,7 @@
 		return 1;
 	}
 
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_jmpbuf(png_ptr))) {
 		// FIXME: must free buffers!!
 		png_destroy_write_struct(&png_ptr, &info_ptr);
 		fclose(fp);
@@ -1888,14 +1889,8 @@
 	png_set_compression_level(png_ptr, Z_BEST_COMPRESSION);
 
 	// prepare the file information
-	info_ptr->width = w;
-	info_ptr->height = h;
-	info_ptr->bit_depth = 8;
-	info_ptr->color_type = PNG_COLOR_TYPE_PALETTE;
-	info_ptr->interlace_type = 0;
-	info_ptr->valid |= PNG_INFO_PLTE;
-	info_ptr->palette = (png_colorp)pal;
-	info_ptr->num_palette = 256;
+	png_set_IHDR(png_ptr, info_ptr, w, h, 8, PNG_COLOR_TYPE_PALETTE, 0, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
+	png_set_PLTE(png_ptr, info_ptr, (png_colorp)pal, 256);
 
 	if (transparent) {
 		unsigned char* p;

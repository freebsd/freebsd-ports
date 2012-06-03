--- f_wrpng.c.orig
+++ f_wrpng.c
@@ -20,6 +20,7 @@
 #include "w_msgpanel.h"
 #include "w_setup.h"
 #include <png.h>
+#include <zlib.h>
 
 /*
  * Write PNG file from rgb data
@@ -59,7 +60,7 @@ write_png(FILE *file, unsigned char *dat
     }
 
     /* set long jump recovery here */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	/* if we get here there was a problem reading the file */
 	png_destroy_write_struct(&png_ptr, &info_ptr);
 	return False;

--- src/util/png.c.orig	2009-07-18 01:50:39.000000000 +0200
+++ src/util/png.c	2012-05-05 08:36:16.000000000 +0200
@@ -3,6 +3,8 @@
 #include <aconfig.h>
 #ifdef USE_PNG
 #include <png.h>
+#include <zlib.h>
+#include <pngpriv.h>
 #endif
 #include <stdlib.h>
 #include <stdio.h>
@@ -59,7 +61,7 @@
 	png_destroy_write_struct(&png_ptr, (png_infopp) NULL);
 	return "No memory to create png info structure";
     }
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	png_destroy_write_struct(&png_ptr, &info_ptr);
 	fclose(file);
 	return strerror(errno);

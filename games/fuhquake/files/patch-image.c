--- image.c.orig	2004-01-07 00:43:22.000000000 +0100
+++ image.c	2012-05-26 15:10:53.000000000 +0200
@@ -24,6 +24,8 @@
 
 #ifdef WITH_PNG
 #include "png.h"
+#include "zlib.h"
+#include "pngpriv.h"
 #endif
 
 #ifdef WITH_JPEG
@@ -569,7 +571,7 @@
 		return NULL;
 	}
 
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_ptr->longjmp_buffer)) {
 		qpng_destroy_read_struct(&png_ptr, &pnginfo, NULL);
 		fclose(fin);
 		return NULL;
@@ -678,7 +680,7 @@
 		return false;
 	}
 
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_ptr->longjmp_buffer)) {
 		qpng_destroy_write_struct(&png_ptr, &info_ptr);
 		fclose(fp);
 		return false;
@@ -743,7 +745,7 @@
 		return false;
 	}
 
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_ptr->longjmp_buffer)) {
 		qpng_destroy_write_struct(&png_ptr, &info_ptr);
 		fclose(fp);
 		return false;

--- src/common/image/ImagePngFactory.cpp.orig	2012-01-10 09:52:15.000000000 +0900
+++ src/common/image/ImagePngFactory.cpp	2012-03-07 18:31:12.000000000 +0900
@@ -62,7 +62,7 @@
 
 static void user_png_error(png_structp png_ptr, png_const_charp msg) 
 {
-	longjmp(png_ptr->jmpbuf,1);
+	longjmp(png_jmpbuf(png_ptr),1);
 }
 
 static void user_png_warning(png_structp png_ptr, png_const_charp msg) 

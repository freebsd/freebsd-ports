--- src/common/image/ImagePngFactory.cpp.orig	2016-06-20 14:16:37 UTC
+++ src/common/image/ImagePngFactory.cpp
@@ -62,7 +62,7 @@ struct user_read_struct
 
 static void user_png_error(png_structp png_ptr, png_const_charp msg) 
 {
-	longjmp(png_ptr->jmpbuf,1);
+	longjmp(png_jmpbuf(png_ptr),1);
 }
 
 static void user_png_warning(png_structp png_ptr, png_const_charp msg) 

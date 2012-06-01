--- src/Util.cpp.orig	2004-05-20 19:42:37.000000000 +0200
+++ src/Util.cpp	2012-05-02 20:49:07.000000000 +0200
@@ -79,7 +79,7 @@
     return false;
   }
 
-  if(setjmp(png_ptr->jmpbuf)) {
+  if(setjmp(png_jmpbuf(png_ptr))) {
     png_destroy_write_struct(&png_ptr,NULL);
     fclose(fp);
     return false;

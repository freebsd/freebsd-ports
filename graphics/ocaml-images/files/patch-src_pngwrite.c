--- src/pngwrite.c.orig	2009-10-26 13:42:03.000000000 +0100
+++ src/pngwrite.c	2012-05-06 13:01:28.000000000 +0200
@@ -62,7 +62,7 @@
   }
 
   /* error handling */
-  if (setjmp(png_ptr->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png_ptr))) {
     /* Free all of the memory associated with the png_ptr and info_ptr */
     png_destroy_write_struct(&png_ptr, &info_ptr);
     fclose(fp);
@@ -171,7 +171,7 @@
   }
 
   /* error handling */
-  if (setjmp(png_ptr->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png_ptr))) {
     /* Free all of the memory associated with the png_ptr and info_ptr */
     png_destroy_write_struct(&png_ptr, &info_ptr);
     fclose(fp);

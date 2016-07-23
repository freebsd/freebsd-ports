--- src/pngread.c.orig	2009-10-26 13:42:03.000000000 +0100
+++ src/pngread.c	2012-05-05 07:08:53.000000000 +0200
@@ -69,7 +69,7 @@
   }
 
   /* error handling */
-  if (setjmp(png_ptr->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png_ptr))) {
     /* Free all of the memory associated with the png_ptr and info_ptr */
     png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
     fclose(fp);
@@ -134,7 +134,7 @@
     png_set_rows(png_ptr, info_ptr, row_pointers);
 
     /* Later, we can return something */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
       /* Free all of the memory associated with the png_ptr and info_ptr */
       png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
       fclose(fp);
@@ -243,7 +243,7 @@
   }
 
   /* error handling */
-  if (setjmp(png_ptr->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png_ptr))) {
     /* Free all of the memory associated with the png_ptr and info_ptr */
     png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
     fclose(fp);
@@ -302,7 +302,7 @@
     png_set_rows(png_ptr, info_ptr, row_pointers);
 
     /* Later, we can return something */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
       /* Free all of the memory associated with the png_ptr and info_ptr */
       png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
       fclose(fp);

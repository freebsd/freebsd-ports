--- source/png/loadpng.c.orig	2005-08-18 10:52:15.000000000 +0200
+++ source/png/loadpng.c	2012-05-06 15:58:26.000000000 +0200
@@ -275,7 +275,7 @@
      * the normal method of doing things with libpng).  REQUIRED unless you
      * set up your own error handlers in the png_create_read_struct() earlier.
      */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	/* Free all of the memory associated with the png_ptr and info_ptr */
 	png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
 	pack_fclose(fp);
@@ -337,7 +337,7 @@
      * the normal method of doing things with libpng).  REQUIRED unless you
      * set up your own error handlers in the png_create_read_struct() earlier.
      */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	/* Free all of the memory associated with the png_ptr and info_ptr */
 	png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
 	/* If we get here, we had a problem reading the file */
@@ -435,7 +435,7 @@
      * the normal method of doing things with libpng).  REQUIRED unless you
      * set up your own error handlers in the png_create_read_struct() earlier.
      */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	/* Free all of the memory associated with the png_ptr and info_ptr */
 	png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
 	/* If we get here, we had a problem reading the file */

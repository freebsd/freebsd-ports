--- source/alleg/png/loadpng.c.orig
+++ source/alleg/png/loadpng.c
@@ -322,7 +322,7 @@
      * the normal method of doing things with libpng).  REQUIRED unless you
      * set up your own error handlers in the png_create_read_struct() earlier.
      */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	/* Free all of the memory associated with the png_ptr and info_ptr */
 	png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
 	fclose(fp);
@@ -384,7 +384,7 @@
      * the normal method of doing things with libpng).  REQUIRED unless you
      * set up your own error handlers in the png_create_read_struct() earlier.
      */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	/* Free all of the memory associated with the png_ptr and info_ptr */
 	png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
 	/* If we get here, we had a problem reading the file */
@@ -482,7 +482,7 @@
      * the normal method of doing things with libpng).  REQUIRED unless you
      * set up your own error handlers in the png_create_read_struct() earlier.
      */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	/* Free all of the memory associated with the png_ptr and info_ptr */
 	png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
 	/* If we get here, we had a problem reading the file */

--- src/simage_png.c.orig	2010-02-26 16:47:31.000000000 +0100
+++ src/simage_png.c	2012-05-05 07:44:14.000000000 +0200
@@ -323,7 +323,7 @@
   /* Set error handling.  REQUIRED if you aren't supplying your own
    * error hadnling functions in the png_create_write_struct() call.
    */
-  if (setjmp(png_ptr->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png_ptr))) {
     /* If we get here, we had a problem reading the file */
     fclose(fp);
     png_destroy_write_struct(&png_ptr,  (png_infopp)info_ptr);

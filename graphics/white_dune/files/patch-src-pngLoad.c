--- src/pngLoad.c.orig	2010-12-09 08:36:57.000000000 +0100
+++ src/pngLoad.c	2012-05-05 08:32:20.000000000 +0200
@@ -139,7 +139,7 @@
     * the normal method of doing things with libpng).  REQUIRED unless you
     * set up your own error handlers in the png_create_read_struct() earlier.
     */
-  if (setjmp(png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(png_ptr)))
     {
       /* If we get here, we had a problem reading the file */
       return 0;

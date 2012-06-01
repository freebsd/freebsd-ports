--- xglk_pict.c.orig	1999-08-26 20:42:12.000000000 +0200
+++ xglk_pict.c	2012-04-29 07:14:20.000000000 +0200
@@ -385,7 +385,7 @@
     return NULL;
   }
 
-  if (setjmp(png_ptr->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png_ptr))) {
     /* If we jump here, we had a problem reading the file */
     png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
     if (rowarray)

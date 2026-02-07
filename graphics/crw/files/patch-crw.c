--- crw.c.orig	2002-07-23 01:17:37.000000000 +0200
+++ crw.c	2012-04-27 07:23:34.000000000 +0200
@@ -1394,7 +1394,7 @@
     png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
     return;
   }
-  if (setjmp(png_ptr->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png_ptr))) {
     png_destroy_write_struct(&png_ptr, &info_ptr);
     return;
   }

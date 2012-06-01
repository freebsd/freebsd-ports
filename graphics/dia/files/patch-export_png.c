--- plug-ins/libart/export_png.c.orig	2009-11-28 13:49:21.000000000 +0100
+++ plug-ins/libart/export_png.c	2012-05-08 07:23:21.000000000 +0200
@@ -178,7 +178,7 @@
   }
 
   /* set error handling ... */
-  if (setjmp(png->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png))) {
     fclose(fp);
     png_destroy_write_struct(&png, &info);
     message_error(_("Error occurred while writing PNG"));

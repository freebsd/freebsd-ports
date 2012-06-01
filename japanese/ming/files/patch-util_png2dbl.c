--- ../util/png2dbl.c.orig	2002-06-24 14:21:54.000000000 +0200
+++ ../util/png2dbl.c	2012-05-06 06:30:46.000000000 +0200
@@ -80,7 +80,7 @@
     error("Couldn't create end_info\n");
   }
 
-  if(setjmp(png_ptr->jmpbuf)) {
+  if(setjmp(png_jmpbuf(png_ptr))) {
     png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
     fclose(fp);
     error("Mystery error (longjmp called)\n");

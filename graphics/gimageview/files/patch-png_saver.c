--- plugins/image_saver/png_saver.c.orig	2004-05-23 16:08:11.000000000 +0200
+++ plugins/image_saver/png_saver.c	2012-05-11 17:57:12.000000000 +0200
@@ -130,7 +130,7 @@
       return FALSE;
    }
 
-   if (setjmp (png_ptr->jmpbuf)) {
+   if (setjmp (png_jmpbuf(png_ptr))) {
       png_destroy_write_struct (&png_ptr, &info_ptr);
       fclose (handle);
       return FALSE;

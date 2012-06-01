--- src/image_cache.c.orig	2003-08-08 09:17:58.000000000 +0200
+++ src/image_cache.c	2012-05-03 23:39:36.000000000 +0200
@@ -782,7 +782,7 @@
       return FALSE;
    }
 
-   if (setjmp (png_ptr->jmpbuf)) {
+   if (setjmp (png_jmpbuf(png_ptr))) {
       png_destroy_write_struct(&png_ptr, &info_ptr);
       fclose (fp);
       return FALSE;

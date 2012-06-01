--- xwin.c.orig	2011-07-26 00:03:37.000000000 +0200
+++ xwin.c	2012-05-01 08:33:19.000000000 +0200
@@ -277,7 +277,7 @@
       fclose(f);
       return 1;
    }
-   if (setjmp(pp->jmpbuf)) {
+   if (setjmp(png_jmpbuf(pp))) {
       png_destroy_write_struct(&pp,&ip);
       fclose(f);
       gdk_image_destroy(image);

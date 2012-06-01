--- plugins/image_loader/png_loader.c.orig	2004-05-23 16:08:16.000000000 +0200
+++ plugins/image_loader/png_loader.c	2012-05-09 12:30:01.000000000 +0200
@@ -255,7 +255,7 @@
       return NULL;
    }
 
-   if (setjmp (png_ptr->jmpbuf)) goto ERROR;
+   if (setjmp (png_jmpbuf(png_ptr))) goto ERROR;
 
    context.gio = gio;
    context.bytes_read = 0;

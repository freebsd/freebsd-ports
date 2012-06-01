--- tools/directfb-csource.c.orig	2011-05-05 20:00:29.000000000 +0200
+++ tools/directfb-csource.c	2012-04-29 06:09:30.000000000 +0200
@@ -41,6 +41,7 @@
 #include <sys/stat.h>
 
 #include <png.h>
+#include <pngpriv.h>
 
 #include <directfb.h>
 
@@ -338,7 +339,7 @@
      if (!png_ptr)
           goto cleanup;
 
-     if (setjmp (png_ptr->jmpbuf)) {
+     if (setjmp (png_jmpbuf(png_ptr))) {
           if (desc->preallocated[0].data) {
                free (desc->preallocated[0].data);
                desc->preallocated[0].data = NULL;

--- tools/mkdfiff.c.orig	2010-10-31 09:49:49.000000000 +0100
+++ tools/mkdfiff.c	2012-04-30 06:43:17.000000000 +0200
@@ -97,7 +97,7 @@
      if (!png_ptr)
           goto cleanup;
 
-     if (setjmp (png_ptr->jmpbuf)) {
+     if (setjmp (png_jmpbuf(png_ptr))) {
           if (desc->preallocated[0].data) {
                free (desc->preallocated[0].data);
                desc->preallocated[0].data = NULL;

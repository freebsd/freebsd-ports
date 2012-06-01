--- tools/mkdgifft.cpp.orig	2011-05-05 20:00:29.000000000 +0200
+++ tools/mkdgifft.cpp	2012-05-01 08:58:04.000000000 +0200
@@ -595,7 +595,7 @@
      if (!png_ptr)
           goto cleanup;
 
-     if (setjmp (png_ptr->jmpbuf)) {
+     if (setjmp (png_jmpbuf(png_ptr))) {
           if (desc->preallocated[0].data) {
                free (desc->preallocated[0].data);
                desc->preallocated[0].data = NULL;

--- src/extension/internal/pdfinput/svg-builder.cpp.orig	2012-05-04 10:06:12.000000000 +0200
+++ src/extension/internal/pdfinput/svg-builder.cpp	2012-05-04 12:24:12.000000000 +0200
@@ -1443,7 +1443,7 @@
         return NULL;
     }
     // Set error handler
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
         png_destroy_write_struct(&png_ptr, &info_ptr);
         return NULL;
     }

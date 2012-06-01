--- src/helper/png-write.cpp.orig	2012-05-04 10:06:13.000000000 +0200
+++ src/helper/png-write.cpp	2012-05-04 12:02:19.000000000 +0200
@@ -165,7 +165,7 @@
     /* Set error handling.  REQUIRED if you aren't supplying your own
      * error hadnling functions in the png_create_write_struct() call.
      */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
         /* If we get here, we had a problem reading the file */
         fclose(fp);
         png_destroy_write_struct(&png_ptr, &info_ptr);

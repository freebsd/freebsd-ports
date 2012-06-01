--- src/screenshot.cpp.orig	2007-09-30 18:07:08.000000000 +0200
+++ src/screenshot.cpp	2012-04-29 06:49:26.000000000 +0200
@@ -159,7 +159,7 @@
       return;
     }
 
-  if (setjmp(png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(png_ptr)))
     {
       // If we get here, we had a problem reading the file
       fclose(fp);

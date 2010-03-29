--- common/im_png.cpp.orig	2000-09-16 19:18:01.000000000 +0200
+++ common/im_png.cpp	2010-03-29 20:47:19.000000000 +0200
@@ -34,7 +34,7 @@
     return NULL;
 
   fread(sig, 1, 8, f);
-  if (!png_check_sig(sig, 8))
+  if (png_sig_cmp(sig, 0, 8))
   {
     fclose(f);
     return NULL;	// bad signature

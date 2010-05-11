--- ./krita/ui/kis_png_converter.cpp.orig	2009-11-20 22:45:35.000000000 +0200
+++ ./krita/ui/kis_png_converter.cpp	2010-03-29 08:23:02.980338247 +0300
@@ -404,7 +404,7 @@
 
     png_byte signature[8];
     iod->peek((char*)signature, 8);
-    if (!png_check_sig(signature, 8)) {
+    if (png_sig_cmp(signature, 0, 8)) {
         iod->close();
         return (KisImageBuilder_RESULT_BAD_FETCH);
     }



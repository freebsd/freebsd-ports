--- handwriting/zinnia_handwriting.cc.orig	2013-03-29 13:33:25.000000000 +0900
+++ handwriting/zinnia_handwriting.cc	2013-04-27 15:15:30.000000000 +0900
@@ -51,7 +51,7 @@
 #elif defined(USE_LIBZINNIA)
   // On Linux, use the model for tegaki-zinnia.
   const char kModelFile[] =
-      "/usr/share/tegaki/models/zinnia/handwriting-ja.model";
+      LOCALBASE "/share/tegaki/models/zinnia/handwriting-ja.model";
   return kModelFile;
 #else
   const char kModelFile[] = "handwriting-ja.model";

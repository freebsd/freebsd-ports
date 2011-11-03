--- plugins/dfbinimage2/Utils.cpp.orig	2011-07-20 07:24:34.070495566 +0200
+++ plugins/dfbinimage2/Utils.cpp	2011-07-20 07:24:48.493222477 +0200
@@ -124,7 +124,7 @@
 #else
    char* buf = getenv("_");
    if (buf == NULL)
-      return "pcsx";
+      return "pcsxr";
 #endif
    else
       toReturn = buf;

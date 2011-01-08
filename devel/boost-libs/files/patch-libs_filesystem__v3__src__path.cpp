--- libs/filesystem/v3/src/path.cpp.orig	2010-12-29 19:30:47.000000000 +0100
+++ libs/filesystem/v3/src/path.cpp	2010-12-29 19:31:36.000000000 +0100
@@ -760,7 +760,7 @@
 
 #   else
     // ISO C calls this "the locale-specific native environment":
-    return std::locale("");
+    return std::locale();
 
 #   endif
   }

--- libs/filesystem/v2/src/v2_path.cpp.orig	2010-12-29 19:23:18.000000000 +0100
+++ libs/filesystem/v2/src/v2_path.cpp	2010-12-29 19:23:54.000000000 +0100
@@ -45,7 +45,7 @@
   {
 #if !defined(macintosh) && !defined(__APPLE__) && !defined(__APPLE_CC__) 
     // ISO C calls this "the locale-specific native environment":
-    static std::locale lc("");
+    static std::locale lc;
 #else  // Mac OS
     // "All BSD system functions expect their string parameters to be in UTF-8 encoding
     // and nothing else."
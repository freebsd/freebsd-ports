--- src/third_party/boost/libs/filesystem/v2/src/v2_path.cpp.orig	2013-05-01 18:59:55.000000000 +0200
+++ src/third_party/boost/libs/filesystem/v2/src/v2_path.cpp	2013-05-01 19:02:01.000000000 +0200
@@ -30,7 +30,7 @@
 
 #include <cwchar>     // for std::mbstate_t
 
-#if defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__) 
+#if defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__) || defined(__FreeBSD__)
 # include <boost/filesystem/detail/utf8_codecvt_facet.hpp>
 #endif
 
@@ -43,7 +43,7 @@
   // occurred before main(), preventing exceptions from being caught.)
   std::locale & loc()
   {
-#if !defined(macintosh) && !defined(__APPLE__) && !defined(__APPLE_CC__) 
+#if !defined(macintosh) && !defined(__APPLE__) && !defined(__APPLE_CC__) && !defined(__FreeBSD__)
     // ISO C calls this "the locale-specific native environment":
     static std::locale lc("");
 #else  // Mac OS

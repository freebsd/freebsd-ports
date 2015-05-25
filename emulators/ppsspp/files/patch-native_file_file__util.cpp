--- native/file/file_util.cpp.orig	2015-02-23 23:22:58 UTC
+++ native/file/file_util.cpp
@@ -25,7 +25,7 @@
 #include "file/file_util.h"
 #include "util/text/utf8.h"
 
-#if defined(__FreeBSD__) || defined(__APPLE__)
+#if !defined(__linux__) && !defined(__SYMBIAN32__)
 #define stat64 stat
 #endif
 

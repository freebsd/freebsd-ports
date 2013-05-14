--- base/logging.cc.orig	2013-04-26 10:49:33.000000000 +0900
+++ base/logging.cc	2013-04-26 10:53:18.000000000 +0900
@@ -111,7 +111,7 @@
 #if defined(__native_client__)
            "%p",
 #elif defined(OS_LINUX)
-           "%lu",
+           "%p",
 #else  // = OS_WIN or OS_MACOSX
            "%u",
 #endif

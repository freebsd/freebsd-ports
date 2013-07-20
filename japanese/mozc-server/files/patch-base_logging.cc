--- base/logging.cc.orig	2013-07-17 11:38:04.000000000 +0900
+++ base/logging.cc	2013-07-19 22:24:20.000000000 +0900
@@ -111,7 +111,7 @@
 #if defined(__native_client__)
            "%p",
 #elif defined(OS_LINUX)
-           "%lu",
+           "%p",
 #elif defined(OS_MACOSX) && defined(__LP64__)
            "%llu",
 #else  // OS_WIN or OS_MACOSX(32bit)

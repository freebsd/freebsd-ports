--- base/logging.cc.orig	2011-12-04 16:22:26.116610643 +0900
+++ base/logging.cc	2011-12-04 19:57:28.052770432 +0900
@@ -212,7 +212,7 @@
   char buf[512];
   snprintf(buf, sizeof(buf),
            "%4.4d-%2.2d-%2.2d %2.2d:%2.2d:%2.2d %u "
-#ifndef OS_LINUX  // = OS_WINDOWS or OS_MACOSX
+#if !defined(OS_LINUX) && !defined(__FreeBSD__) // = OS_WINDOWS or OS_MACOSX
            "%u",
 #else
            "%lu",
@@ -229,6 +229,9 @@
 #elif defined(OS_MACOSX)
            ::getpid(),
            reinterpret_cast<uint32>(pthread_self())
+#elif defined(__FreeBSD__)
+           ::getpid(),
+           (uint64_t)pthread_self()
 #else  // = OS_LINUX
            ::getpid(),
            pthread_self()  // returns unsigned long.

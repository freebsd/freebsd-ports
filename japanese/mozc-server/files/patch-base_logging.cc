--- base/logging.cc.orig	2012-01-29 13:42:31.194805201 +0900
+++ base/logging.cc	2012-01-29 13:49:21.256805888 +0900
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

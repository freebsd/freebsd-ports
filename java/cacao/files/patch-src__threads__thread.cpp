--- src/threads/thread.cpp.orig	2013-06-28 09:22:26.000000000 -0400
+++ src/threads/thread.cpp	2013-07-08 15:41:56.000000000 -0400
@@ -51,6 +51,8 @@
 #if defined(ENABLE_GC_BOEHM)
 # if defined(__LINUX__)
 #  define GC_LINUX_THREADS
+# elif defined(__FREEBSD__)
+#  define GC_FREEBSD_THREADS
 # elif defined(__IRIX__)
 #  define GC_IRIX_THREADS
 # elif defined(__DARWIN__)

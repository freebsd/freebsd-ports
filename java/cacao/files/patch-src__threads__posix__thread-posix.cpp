--- src/threads/posix/thread-posix.cpp.orig	2012-09-03 12:10:00.000000000 -0400
+++ src/threads/posix/thread-posix.cpp	2012-10-04 16:42:49.000000000 -0400
@@ -94,6 +94,8 @@
 
 #if defined(__LINUX__)
 # define GC_LINUX_THREADS
+#elif defined(__FREEBSD__)
+# define GC_FREEBSD_THREADS
 #elif defined(__IRIX__)
 # define GC_IRIX_THREADS
 #elif defined(__DARWIN__)

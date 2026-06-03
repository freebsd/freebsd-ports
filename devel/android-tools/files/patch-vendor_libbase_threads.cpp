--- vendor/libbase/threads.cpp.orig	2024-08-29 19:46:57.000000000 +0200
+++ vendor/libbase/threads.cpp	2026-03-24 12:00:00.000000000 +0100
@@ -21,6 +21,8 @@

 #if defined(__APPLE__)
 #include <pthread.h>
+#elif defined(__FreeBSD__)
+#include <pthread_np.h>
 #elif defined(__linux__) && !defined(__ANDROID__)
 #include <syscall.h>
 #elif defined(_WIN32)
@@ -37,6 +39,8 @@
   uint64_t tid;
   pthread_threadid_np(NULL, &tid);
   return tid;
+#elif defined(__FreeBSD__)
+  return pthread_getthreadid_np();
 #elif defined(__linux__)
   return syscall(__NR_gettid);
 #elif defined(_WIN32)

--- libcutils/threads.cpp.orig	2018-07-13 19:58:45 UTC
+++ libcutils/threads.cpp
@@ -24,11 +24,21 @@
 #include <sys/syscall.h>
 #include <sys/time.h>
 #include <unistd.h>
+#elif defined(__DragonFly__) || defined(__FreeBSD__)
+#include <pthread_np.h>
+#elif defined(__NetBSD__)
+#include <lwp.h>
+#elif defined(__OpenBSD__)
+#include <unistd.h>
+#elif defined(__sun)
+#include <thread.h>
 #elif defined(__linux__) && !defined(__ANDROID__)
 #include <syscall.h>
 #include <unistd.h>
 #elif defined(_WIN32)
 #include <windows.h>
+#else // fallback
+#include <stdint.h>
 #endif
 
 // No definition needed for Android because we'll just pick up bionic's copy.
@@ -38,10 +46,20 @@ pid_t gettid() {
   uint64_t tid;
   pthread_threadid_np(NULL, &tid);
   return tid;
+#elif defined(__DragonFly__) || defined(__FreeBSD__)
+  return pthread_getthreadid_np();
+#elif defined(__NetBSD__)
+  return _lwp_self();
+#elif defined(__OpenBSD__)
+  return getthrid();
+#elif defined(__sun)
+  return thr_self();
 #elif defined(__linux__)
   return syscall(__NR_gettid);
 #elif defined(_WIN32)
   return GetCurrentThreadId();
+#else // fallback
+  return (intptr_t) pthread_self();
 #endif
 }
 #endif  // __ANDROID__

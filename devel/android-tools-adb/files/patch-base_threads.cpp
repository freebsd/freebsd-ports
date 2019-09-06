--- base/threads.cpp.orig	2019-07-17 19:54:09 UTC
+++ base/threads.cpp
@@ -25,6 +25,16 @@
 #include <syscall.h>
 #elif defined(_WIN32)
 #include <windows.h>
+#elif defined(__DragonFly__) || defined(__FreeBSD__)
+#include <pthread_np.h>
+#elif defined(__NetBSD__)
+#include <lwp.h>
+#elif defined(__OpenBSD__)
+#include <unistd.h>
+#elif defined(__sun)
+#include <thread.h>
+#else // fallback
+#include <stdint.h>
 #endif
 
 namespace android {
@@ -41,6 +51,16 @@ uint64_t GetThreadId() {
   return syscall(__NR_gettid);
 #elif defined(_WIN32)
   return GetCurrentThreadId();
+#elif defined(__DragonFly__) || defined(__FreeBSD__)
+  return pthread_getthreadid_np();
+#elif defined(__NetBSD__)
+  return _lwp_self();
+#elif defined(__OpenBSD__)
+  return getthrid();
+#elif defined(__sun)
+  return thr_self();
+#else // fallback
+  return (intptr_t) pthread_self();
 #endif
 }
 

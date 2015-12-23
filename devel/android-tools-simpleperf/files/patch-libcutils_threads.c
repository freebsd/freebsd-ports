--- libcutils/threads.c.orig	2015-06-17 22:20:38 UTC
+++ libcutils/threads.c
@@ -29,6 +29,14 @@
 #include <unistd.h>
 #elif defined(_WIN32)
 #include <windows.h>
+#elif defined(__DragonFly__)
+#include <unistd.h>
+#elif defined(__FreeBSD__)
+#include <pthread_np.h>
+#elif defined(__NetBSD__)
+#include <lwp.h>
+#else
+#include <stdint.h>
 #endif
 
 // No definition needed for Android because we'll just pick up bionic's copy.
@@ -40,6 +48,14 @@ pid_t gettid() {
   return syscall(__NR_gettid);
 #elif defined(_WIN32)
   return GetCurrentThreadId();
+#elif defined(__DragonFly__)
+  return lwp_gettid();
+#elif defined(__NetBSD__)
+  return _lwp_self();
+#elif defined(__FreeBSD__)
+  return pthread_getthreadid_np();
+#else
+  return (intptr_t) pthread_self();
 #endif
 }
 #endif  // __ANDROID__

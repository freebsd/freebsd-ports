--- liblog/logger_write.cpp.orig	2020-02-11 20:44:45 UTC
+++ liblog/logger_write.cpp
@@ -51,6 +51,16 @@
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
 
 using android::base::ErrnoRestorer;
@@ -248,6 +258,16 @@ static uint64_t GetThreadId() {
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
 

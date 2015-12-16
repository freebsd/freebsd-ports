--- base/logging.cpp.orig	2015-12-14 21:12:52 UTC
+++ base/logging.cpp
@@ -66,6 +68,16 @@
 #include <unistd.h>
 #elif defined(_WIN32)
 #include <windows.h>
+#elif defined(__DragonFly__)
+#include <unistd.h>
+#elif defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/thr.h>
+#include <pthread_np.h>
+#elif defined(__NetBSD__)
+#include <lwp.h>
+#else
+#include <stdint.h>
 #endif
 
 static pid_t GetThreadId() {
@@ -77,6 +89,20 @@ static pid_t GetThreadId() {
   return syscall(__NR_gettid);
 #elif defined(_WIN32)
   return GetCurrentThreadId();
+#elif defined(__DragonFly__)
+  return lwp_gettid();
+#elif defined(__NetBSD__)
+  return _lwp_self();
+#elif defined(__FreeBSD__)
+#  if __FreeBSD_version > 900030
+    return pthread_getthreadid_np();
+#  else
+    long lwpid;
+    thr_self(&lwpid);
+    return lwpid;
+#  endif
+#else
+  return (intptr_t) pthread_self();
 #endif
 }
 

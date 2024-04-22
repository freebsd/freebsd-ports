--- third_party/abseil-cpp/absl/base/internal/sysinfo.cc.orig	2024-02-20 20:56:37 UTC
+++ third_party/abseil-cpp/absl/base/internal/sysinfo.cc
@@ -42,6 +42,10 @@
 #include <lwp.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <pthread_np.h>
+#endif
+
 #if defined(__myriad2__)
 #include <rtems.h>
 #endif
@@ -429,14 +433,18 @@ pid_t GetTID() {
   return tid;
 }
 
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 
 pid_t GetTID() {
   uint64_t tid;
   // `nullptr` here implies this thread.  This only fails if the specified
   // thread is invalid or the pointer-to-tid is null, so we needn't worry about
   // it.
+#if __FreeBSD__
+  tid = pthread_getthreadid_np();
+#else
   pthread_threadid_np(nullptr, &tid);
+#endif
   return static_cast<pid_t>(tid);
 }
 

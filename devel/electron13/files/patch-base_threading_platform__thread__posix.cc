--- base/threading/platform_thread_posix.cc.orig	2021-07-15 19:13:30 UTC
+++ base/threading/platform_thread_posix.cc
@@ -32,6 +32,10 @@
 #include <sys/syscall.h>
 #endif
 
+#if defined(OS_BSD)
+#include <pthread_np.h>
+#endif
+
 #if defined(OS_FUCHSIA)
 #include <zircon/process.h>
 #else
@@ -181,6 +185,8 @@ PlatformThreadId PlatformThread::CurrentId() {
   // into the kernel.
 #if defined(OS_APPLE)
   return pthread_mach_thread_np(pthread_self());
+#elif defined(OS_BSD)
+  return pthread_getthreadid_np();
 #elif defined(OS_LINUX) || defined(OS_CHROMEOS)
   static NoDestructor<InitAtFork> init_at_fork;
   if (g_thread_id == -1) {

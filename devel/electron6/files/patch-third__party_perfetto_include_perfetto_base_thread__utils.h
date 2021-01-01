--- third_party/perfetto/include/perfetto/base/thread_utils.h.orig	2019-09-10 11:16:55 UTC
+++ third_party/perfetto/include/perfetto/base/thread_utils.h
@@ -33,6 +33,10 @@
 #include <unistd.h>
 #endif
 
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+#include <pthread_np.h>
+#endif
+
 namespace perfetto {
 namespace base {
 
@@ -40,6 +44,11 @@ namespace base {
 using PlatformThreadID = pid_t;
 inline PlatformThreadID GetThreadId() {
   return gettid();
+}
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+      using PlatformThreadID = int;
+inline PlatformThreadID GetThreadId() {
+  return pthread_getthreadid_np();
 }
 #elif PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX)
 using PlatformThreadID = pid_t;

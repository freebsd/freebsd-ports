--- third_party/perfetto/include/perfetto/base/thread_utils.h.orig	2022-11-30 08:12:58 UTC
+++ third_party/perfetto/include/perfetto/base/thread_utils.h
@@ -35,6 +35,7 @@ __declspec(dllimport) unsigned long __stdcall GetCurre
 #include <sys/syscall.h>
 #include <sys/types.h>
 #include <unistd.h>
+#include <pthread.h>
 #else
 #include <pthread.h>
 #endif
@@ -46,6 +47,11 @@ namespace base {
 using PlatformThreadId = pid_t;
 inline PlatformThreadId GetThreadId() {
   return gettid();
+}
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
+using PlatformThreadId = uint64_t;
+inline PlatformThreadId GetThreadId() {
+  return reinterpret_cast<uint64_t>(pthread_self());
 }
 #elif PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX)
 using PlatformThreadId = pid_t;

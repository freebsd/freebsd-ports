--- third_party/perfetto/include/perfetto/base/thread_utils.h.orig	2025-03-24 20:50:14 UTC
+++ third_party/perfetto/include/perfetto/base/thread_utils.h
@@ -37,6 +37,7 @@ __declspec(dllimport) unsigned long __stdcall GetCurre
 #include <sys/syscall.h>
 #include <sys/types.h>
 #include <unistd.h>
+#include <pthread.h>
 #else
 #include <pthread.h>
 #endif
@@ -49,6 +50,11 @@ inline PlatformThreadId GetThreadId() {
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

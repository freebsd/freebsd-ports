Backport of Perfetto's FreeBSD support (upstream 81c39c7f82, Perfetto
v53) to the Perfetto that Dart 3.13 pins (series 1001). Drop it once
Dart pins Perfetto v53 or later.
--- third_party/perfetto/src/include/perfetto/base/thread_utils.h.orig	2026-09-29 08:00:52 UTC
+++ third_party/perfetto/src/include/perfetto/base/thread_utils.h
@@ -38,6 +38,10 @@ __declspec(dllimport) unsigned long __stdcall GetCurre
 #include <pthread.h>
 #endif
 
+#if defined(__FreeBSD__)
+#include <pthread_np.h>
+#endif
+
 namespace perfetto {
 namespace base {
 
@@ -45,6 +49,11 @@ inline PlatformThreadId GetThreadId() {
 using PlatformThreadId = pid_t;
 inline PlatformThreadId GetThreadId() {
   return gettid();
+}
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) && defined(__FreeBSD__)
+using PlatformThreadId = pid_t;
+inline PlatformThreadId GetThreadId() {
+  return static_cast<pid_t>(pthread_getthreadid_np());
 }
 #elif PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX)
 using PlatformThreadId = pid_t;

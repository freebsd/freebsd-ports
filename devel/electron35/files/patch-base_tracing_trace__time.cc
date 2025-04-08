--- base/tracing/trace_time.cc.orig	2025-03-24 20:50:14 UTC
+++ base/tracing/trace_time.cc
@@ -8,12 +8,16 @@
 #include "build/build_config.h"
 #include "third_party/perfetto/include/perfetto/base/time.h"
 
+#if BUILDFLAG(IS_FREEBSD)
+#define CLOCK_BOOTTIME CLOCK_UPTIME
+#endif
+
 namespace base::tracing {
 
 int64_t TraceBootTicksNow() {
   // On Windows and Mac, TRACE_TIME_TICKS_NOW() behaves like boottime already.
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   struct timespec ts;
   int res = clock_gettime(CLOCK_BOOTTIME, &ts);
   if (res != -1) {

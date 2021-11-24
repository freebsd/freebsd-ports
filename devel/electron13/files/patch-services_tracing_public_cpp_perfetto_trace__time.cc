--- services/tracing/public/cpp/perfetto/trace_time.cc.orig	2021-07-15 19:13:43 UTC
+++ services/tracing/public/cpp/perfetto/trace_time.cc
@@ -12,10 +12,14 @@ namespace tracing {
 
 int64_t TraceBootTicksNow() {
   // On Windows and Mac, TRACE_TIME_TICKS_NOW() behaves like boottime already.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
+#if defined(OS_BSD) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
     defined(OS_FUCHSIA)
   struct timespec ts;
+#if defined(OS_BSD)
+  int res = clock_gettime(CLOCK_MONOTONIC, &ts);
+#else
   int res = clock_gettime(CLOCK_BOOTTIME, &ts);
+#endif
   if (res != -1)
     return static_cast<int64_t>(perfetto::base::FromPosixTimespec(ts).count());
 #endif

--- services/tracing/public/cpp/perfetto/trace_time.cc.orig	2021-01-07 00:36:40 UTC
+++ services/tracing/public/cpp/perfetto/trace_time.cc
@@ -12,14 +12,18 @@ namespace tracing {
 
 int64_t TraceBootTicksNow() {
   // On Windows and Mac, TRACE_TIME_TICKS_NOW() behaves like boottime already.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD) || \
     defined(OS_FUCHSIA)
   struct timespec ts;
+  int res = clock_gettime(CLOCK_UPTIME, &ts);
+#if defined(OS_BSD)
+#else
   int res = clock_gettime(CLOCK_BOOTTIME, &ts);
+#endif
   if (res != -1)
     return static_cast<int64_t>(perfetto::base::FromPosixTimespec(ts).count());
 #endif
   return TRACE_TIME_TICKS_NOW().since_origin().InNanoseconds();
 }
 
-}  // namespace tracing
\ No newline at end of file
+}  // namespace tracing

--- services/tracing/public/cpp/perfetto/trace_time.h.orig	2021-07-15 19:13:43 UTC
+++ services/tracing/public/cpp/perfetto/trace_time.h
@@ -10,7 +10,7 @@
 
 namespace tracing {
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
+#if defined(OS_BSD) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
     defined(OS_FUCHSIA)
 // Linux, Android, and Fuchsia all use CLOCK_MONOTONIC. See crbug.com/166153
 // about efforts to unify base::TimeTicks across all platforms.

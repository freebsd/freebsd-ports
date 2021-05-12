--- base/profiler/sampling_profiler_thread_token.cc.orig	2021-01-07 00:36:18 UTC
+++ base/profiler/sampling_profiler_thread_token.cc
@@ -7,7 +7,7 @@
 namespace base {
 
 SamplingProfilerThreadToken GetSamplingProfilerCurrentThreadToken() {
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return {PlatformThread::CurrentId(), pthread_self()};
 #else
   return {PlatformThread::CurrentId()};

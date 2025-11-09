--- base/profiler/sampling_profiler_thread_token.h.orig	2025-04-22 20:15:27 UTC
+++ base/profiler/sampling_profiler_thread_token.h
@@ -13,7 +13,7 @@
 
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_APPLE)
 #include <pthread.h>
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <stdint.h>
 #endif
 
@@ -27,7 +27,7 @@ struct SamplingProfilerThreadToken {
   PlatformThreadId id;
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_APPLE)
   pthread_t pthread_id;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Due to the sandbox, we can only retrieve the stack base address for the
   // current thread. We must grab it during
   // GetSamplingProfilerCurrentThreadToken() and not try to get it later.

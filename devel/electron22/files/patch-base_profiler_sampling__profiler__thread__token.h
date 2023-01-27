--- base/profiler/sampling_profiler_thread_token.h.orig	2022-10-24 13:33:33 UTC
+++ base/profiler/sampling_profiler_thread_token.h
@@ -11,7 +11,7 @@
 
 #if BUILDFLAG(IS_ANDROID)
 #include <pthread.h>
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <stdint.h>
 #endif
 
@@ -25,7 +25,7 @@ struct SamplingProfilerThreadToken {
   PlatformThreadId id;
 #if BUILDFLAG(IS_ANDROID)
   pthread_t pthread_id;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Due to the sandbox, we can only retrieve the stack base address for the
   // current thread. We must grab it during
   // GetSamplingProfilerCurrentThreadToken() and not try to get it later.

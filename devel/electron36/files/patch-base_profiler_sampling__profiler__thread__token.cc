--- base/profiler/sampling_profiler_thread_token.cc.orig	2025-04-22 20:15:27 UTC
+++ base/profiler/sampling_profiler_thread_token.cc
@@ -6,7 +6,7 @@
 
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <pthread.h>
 
 #include "base/profiler/stack_base_address_posix.h"
@@ -18,7 +18,7 @@ SamplingProfilerThreadToken GetSamplingProfilerCurrent
   PlatformThreadId id = PlatformThread::CurrentId();
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_APPLE)
   return {id, pthread_self()};
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::optional<uintptr_t> maybe_stack_base =
       GetThreadStackBaseAddress(id, pthread_self());
   return {id, maybe_stack_base};

--- base/features.cc.orig	2024-06-18 21:43:17 UTC
+++ base/features.cc
@@ -9,7 +9,7 @@
 #include "base/threading/platform_thread.h"
 #include "build/buildflag.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "base/message_loop/message_pump_libevent.h"
 #endif
 
@@ -98,7 +98,7 @@ void Init(EmitThreadControllerProfilerMetadata
   sequence_manager::internal::ThreadController::InitializeFeatures(
       emit_thread_controller_profiler_metadata);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   MessagePumpLibevent::InitializeFeatures();
 #endif
 

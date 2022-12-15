--- content/utility/services.cc.orig	2022-07-22 17:30:31 UTC
+++ content/utility/services.cc
@@ -63,7 +63,7 @@
 extern sandbox::TargetServices* g_utility_target_services;
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "sandbox/linux/services/libc_interceptor.h"
 #include "sandbox/policy/mojom/sandbox.mojom.h"
 #include "sandbox/policy/sandbox_type.h"
@@ -85,7 +85,7 @@ extern sandbox::TargetServices* g_utility_target_servi
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH) && (BUILDFLAG(USE_VAAPI) ||
         // BUILDFLAG(USE_V4L2_CODEC))
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)) && \
     (BUILDFLAG(USE_VAAPI) || BUILDFLAG(USE_V4L2_CODEC))
 #include "media/mojo/services/stable_video_decoder_factory_service.h"  // nogncheck
 #endif  // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)) &&
@@ -198,7 +198,7 @@ auto RunAudio(mojo::PendingReceiver<audio::mojom::Audi
       << "task_policy_set TASK_QOS_POLICY";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   auto* command_line = base::CommandLine::ForCurrentProcess();
   if (sandbox::policy::SandboxTypeFromCommandLine(*command_line) ==
       sandbox::mojom::Sandbox::kNoSandbox) {
@@ -288,7 +288,7 @@ auto RunOOPArcVideoAcceleratorFactoryService(
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH) && (BUILDFLAG(USE_VAAPI) ||
         // BUILDFLAG(USE_V4L2_CODEC))
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)) && \
     (BUILDFLAG(USE_VAAPI) || BUILDFLAG(USE_V4L2_CODEC))
 auto RunStableVideoDecoderFactoryService(
     mojo::PendingReceiver<media::stable::mojom::StableVideoDecoderFactory>
@@ -342,7 +342,7 @@ void RegisterMainThreadServices(mojo::ServiceFactory& 
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH) && (BUILDFLAG(USE_VAAPI) ||
         // BUILDFLAG(USE_V4L2_CODEC))
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)) && \
     (BUILDFLAG(USE_VAAPI) || BUILDFLAG(USE_V4L2_CODEC))
   services.Add(RunStableVideoDecoderFactoryService);
 #endif  // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)) &&

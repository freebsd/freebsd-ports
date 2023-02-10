--- content/utility/utility_main.cc.orig	2022-11-30 08:12:58 UTC
+++ content/utility/utility_main.cc
@@ -31,17 +31,19 @@
 #include "third_party/icu/source/common/unicode/unistr.h"
 #include "third_party/icu/source/i18n/unicode/timezone.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/utility/speech/speech_recognition_sandbox_hook_linux.h"
 #if BUILDFLAG(ENABLE_PRINTING)
 #include "printing/sandbox/print_backend_sandbox_hook_linux.h"
 #endif
+#if !BUILDFLAG(IS_BSD)
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 #include "services/audio/audio_sandbox_hook_linux.h"
 #include "services/network/network_sandbox_hook_linux.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 #include "gpu/config/gpu_info_collector.h"
 #include "media/gpu/sandbox/hardware_video_decoding_sandbox_hook_linux.h"
 
@@ -50,6 +52,10 @@
 #include "third_party/angle/src/gpu_info_util/SystemInfo.h"  // nogncheck
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
 
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/openbsd/sandbox_openbsd.h"
+#endif
+
 #if BUILDFLAG(IS_CHROMEOS_ASH)
 #include "ash/services/ime/ime_sandbox_hook.h"
 #include "chromeos/ash/components/assistant/buildflags.h"
@@ -130,7 +136,7 @@ int UtilityMain(MainFunctionParams parameters) {
     }
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Initializes the sandbox before any threads are created.
   // TODO(jorgelo): move this after GTK initialization when we enable a strict
   // Seccomp-BPF policy.
@@ -158,7 +164,7 @@ int UtilityMain(MainFunctionParams parameters) {
       pre_sandbox_hook = base::BindOnce(&screen_ai::ScreenAIPreSandboxHook);
       break;
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
     case sandbox::mojom::Sandbox::kHardwareVideoDecoding:
       pre_sandbox_hook =
           base::BindOnce(&media::HardwareVideoDecodingPreSandboxHook);
@@ -181,10 +187,11 @@ int UtilityMain(MainFunctionParams parameters) {
     default:
       break;
   }
+#if !BUILDFLAG(IS_BSD)
   if (!sandbox::policy::IsUnsandboxedSandboxType(sandbox_type) &&
       (parameters.zygote_child || !pre_sandbox_hook.is_null())) {
     sandbox::policy::SandboxLinux::Options sandbox_options;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
     if (sandbox_type == sandbox::mojom::Sandbox::kHardwareVideoDecoding) {
       // The kHardwareVideoDecoding sandbox needs to know the GPU type in order
       // to select the right policy.
@@ -197,6 +204,11 @@ int UtilityMain(MainFunctionParams parameters) {
     sandbox::policy::Sandbox::Initialize(
         sandbox_type, std::move(pre_sandbox_hook), sandbox_options);
   }
+#else
+  sandbox::policy::Sandbox::Initialize(
+      sandbox_type, std::move(pre_sandbox_hook),
+      sandbox::policy::SandboxLinux::Options());
+#endif
 #elif BUILDFLAG(IS_WIN)
   g_utility_target_services = parameters.sandbox_info->target_services;
 #endif

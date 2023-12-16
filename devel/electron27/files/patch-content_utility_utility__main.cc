--- content/utility/utility_main.cc.orig	2023-10-19 19:58:23 UTC
+++ content/utility/utility_main.cc
@@ -34,7 +34,7 @@
 #include "third_party/icu/source/common/unicode/unistr.h"
 #include "third_party/icu/source/i18n/unicode/timezone.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/file_descriptor_store.h"
 #include "base/files/file_util.h"
 #include "base/pickle.h"
@@ -42,7 +42,9 @@
 #include "content/utility/speech/speech_recognition_sandbox_hook_linux.h"
 #include "gpu/config/gpu_info_collector.h"
 #include "media/gpu/sandbox/hardware_video_encoding_sandbox_hook_linux.h"
+#if !BUILDFLAG(IS_BSD)
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 #include "services/audio/audio_sandbox_hook_linux.h"
 #include "services/network/network_sandbox_hook_linux.h"
 // gn check is not smart enough to realize that this include only applies to
@@ -54,10 +56,14 @@
 #endif
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 #include "media/gpu/sandbox/hardware_video_decoding_sandbox_hook_linux.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
 
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#endif
+
 #if BUILDFLAG(IS_CHROMEOS_ASH)
 #include "chromeos/ash/components/assistant/buildflags.h"
 #include "chromeos/ash/services/ime/ime_sandbox_hook.h"
@@ -69,7 +75,7 @@
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
 #if (BUILDFLAG(ENABLE_SCREEN_AI_SERVICE) && \
-     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)))
+     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)))
 #include "components/services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.h"  // nogncheck
 #endif
 
@@ -95,7 +101,7 @@ namespace content {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 std::vector<std::string> GetNetworkContextsParentDirectories() {
   base::MemoryMappedFile::Region region;
   base::ScopedFD read_pipe_fd = base::FileDescriptorStore::GetInstance().TakeFD(
@@ -123,7 +129,7 @@ std::vector<std::string> GetNetworkContextsParentDirec
 
 bool ShouldUseAmdGpuPolicy(sandbox::mojom::Sandbox sandbox_type) {
   const bool obtain_gpu_info =
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
       sandbox_type == sandbox::mojom::Sandbox::kHardwareVideoDecoding ||
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
       sandbox_type == sandbox::mojom::Sandbox::kHardwareVideoEncoding;
@@ -239,7 +245,7 @@ int UtilityMain(MainFunctionParams parameters) {
     }
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Initializes the sandbox before any threads are created.
   // TODO(jorgelo): move this after GTK initialization when we enable a strict
   // Seccomp-BPF policy.
@@ -268,7 +274,7 @@ int UtilityMain(MainFunctionParams parameters) {
       pre_sandbox_hook = base::BindOnce(&screen_ai::ScreenAIPreSandboxHook);
       break;
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
     case sandbox::mojom::Sandbox::kHardwareVideoDecoding:
       pre_sandbox_hook =
           base::BindOnce(&media::HardwareVideoDecodingPreSandboxHook);
@@ -295,6 +301,7 @@ int UtilityMain(MainFunctionParams parameters) {
     default:
       break;
   }
+#if !BUILDFLAG(IS_BSD)
   if (!sandbox::policy::IsUnsandboxedSandboxType(sandbox_type) &&
       (parameters.zygote_child || !pre_sandbox_hook.is_null())) {
     sandbox::policy::SandboxLinux::Options sandbox_options;
@@ -303,6 +310,11 @@ int UtilityMain(MainFunctionParams parameters) {
     sandbox::policy::Sandbox::Initialize(
         sandbox_type, std::move(pre_sandbox_hook), sandbox_options);
   }
+#else
+  sandbox::policy::Sandbox::Initialize(
+      sandbox_type, std::move(pre_sandbox_hook),
+      sandbox::policy::SandboxLinux::Options());
+#endif
 
   // Start the HangWatcher now that the sandbox is engaged, if it hasn't
   // already been started.

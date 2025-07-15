--- content/utility/utility_main.cc.orig	2025-06-30 07:04:30 UTC
+++ content/utility/utility_main.cc
@@ -37,15 +37,19 @@
 #include "services/tracing/public/cpp/trace_startup.h"
 #include "services/video_effects/public/cpp/buildflags.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/file_descriptor_store.h"
 #include "base/files/file_util.h"
 #include "base/pickle.h"
 #include "content/child/sandboxed_process_thread_type_handler.h"
+#if !BUILDFLAG(IS_BSD)
 #include "content/common/gpu_pre_sandbox_hook_linux.h"
+#endif
 #include "content/public/common/content_descriptor_keys.h"
 #include "content/utility/speech/speech_recognition_sandbox_hook_linux.h"
+#if !BUILDFLAG(IS_BSD)
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 #include "services/audio/audio_sandbox_hook_linux.h"
 #include "services/network/network_sandbox_hook_linux.h"
 #include "services/screen_ai/buildflags/buildflags.h"
@@ -70,7 +74,12 @@
 
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(ENABLE_VIDEO_EFFECTS) && BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#include "content/common/gpu_pre_sandbox_hook_bsd.h"
+#endif
+
+#if BUILDFLAG(ENABLE_VIDEO_EFFECTS) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #include "services/video_effects/video_effects_sandbox_hook_linux.h"  // nogncheck
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -105,7 +114,7 @@ sandbox::TargetServices* g_utility_target_services = n
 sandbox::TargetServices* g_utility_target_services = nullptr;
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(ENABLE_ON_DEVICE_TRANSLATION) && BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(ENABLE_ON_DEVICE_TRANSLATION) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #include "components/services/on_device_translation/sandbox_hook.h"
 #endif  // BUILDFLAG(ENABLE_ON_DEVICE_TRANSLATION) && BUILDFLAG(IS_LINUX)
 
@@ -113,7 +122,7 @@ namespace {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 std::vector<std::string> GetNetworkContextsParentDirectories() {
   base::MemoryMappedFile::Region region;
   base::ScopedFD read_pipe_fd = base::FileDescriptorStore::GetInstance().TakeFD(
@@ -252,7 +261,8 @@ int UtilityMain(MainFunctionParams parameters) {
     CHECK(on_device_model::OnDeviceModelService::PreSandboxInit());
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+// XXX BSD
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_BSD)
   // Thread type delegate of the process should be registered before first
   // thread type change in ChildProcess constructor. It also needs to be
   // registered before the process has multiple threads, which may race with
@@ -260,7 +270,7 @@ int UtilityMain(MainFunctionParams parameters) {
   SandboxedProcessThreadTypeHandler::Create();
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Initializes the sandbox before any threads are created.
   // TODO(jorgelo): move this after GTK initialization when we enable a strict
   // Seccomp-BPF policy.
@@ -292,7 +302,7 @@ int UtilityMain(MainFunctionParams parameters) {
       pre_sandbox_hook =
           base::BindOnce(&speech::SpeechRecognitionPreSandboxHook);
       break;
-#if BUILDFLAG(ENABLE_ON_DEVICE_TRANSLATION) && BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(ENABLE_ON_DEVICE_TRANSLATION) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
     case sandbox::mojom::Sandbox::kOnDeviceTranslation:
       pre_sandbox_hook = base::BindOnce(
           &on_device_translation::OnDeviceTranslationSandboxHook);
@@ -308,7 +318,7 @@ int UtilityMain(MainFunctionParams parameters) {
 #else
       NOTREACHED();
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case sandbox::mojom::Sandbox::kVideoEffects:
 #if BUILDFLAG(ENABLE_VIDEO_EFFECTS)
       pre_sandbox_hook =
@@ -343,6 +353,7 @@ int UtilityMain(MainFunctionParams parameters) {
     default:
       break;
   }
+#if !BUILDFLAG(IS_BSD)
   if (!sandbox::policy::IsUnsandboxedSandboxType(sandbox_type) &&
       (parameters.zygote_child || !pre_sandbox_hook.is_null())) {
     sandbox_options.use_amd_specific_policies =
@@ -350,6 +361,11 @@ int UtilityMain(MainFunctionParams parameters) {
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

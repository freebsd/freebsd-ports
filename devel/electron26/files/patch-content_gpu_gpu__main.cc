--- content/gpu/gpu_main.cc.orig	2023-08-20 00:00:06 UTC
+++ content/gpu/gpu_main.cc
@@ -90,7 +90,7 @@
 #include "sandbox/win/src/sandbox.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/gpu/gpu_sandbox_hook_linux.h"
 #include "sandbox/policy/linux/sandbox_linux.h"
 #include "sandbox/policy/sandbox_type.h"
@@ -112,7 +112,7 @@ namespace content {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread*,
                        const gpu::GPUInfo*,
                        const gpu::GpuPreferences&);
@@ -177,7 +177,7 @@ class ContentSandboxHelper : public gpu::GpuSandboxHel
   bool EnsureSandboxInitialized(gpu::GpuWatchdogThread* watchdog_thread,
                                 const gpu::GPUInfo* gpu_info,
                                 const gpu::GpuPreferences& gpu_prefs) override {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     return StartSandboxLinux(watchdog_thread, gpu_info, gpu_prefs);
 #elif BUILDFLAG(IS_WIN)
     return StartSandboxWindows(sandbox_info_);
@@ -291,7 +291,7 @@ int GpuMain(MainFunctionParams parameters) {
           std::make_unique<base::SingleThreadTaskExecutor>(
               gpu_preferences.message_pump_type);
     }
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #error "Unsupported Linux platform."
 #elif BUILDFLAG(IS_MAC)
     // Cross-process CoreAnimation requires a CFRunLoop to function at all, and
@@ -425,7 +425,7 @@ int GpuMain(MainFunctionParams parameters) {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread* watchdog_thread,
                        const gpu::GPUInfo* gpu_info,
                        const gpu::GpuPreferences& gpu_prefs) {
@@ -465,7 +465,7 @@ bool StartSandboxLinux(gpu::GpuWatchdogThread* watchdo
   sandbox_options.accelerated_video_encode_enabled =
       !gpu_prefs.disable_accelerated_video_encode;
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Video decoding of many video streams can use thousands of FDs as well as
   // Exo clients like Lacros.
   // See https://crbug.com/1417237

--- content/gpu/gpu_main.cc.orig	2019-04-09 12:48:19 UTC
+++ content/gpu/gpu_main.cc
@@ -78,7 +78,7 @@
 #include "ui/gfx/x/x11_switches.h"    // nogncheck
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "content/gpu/gpu_sandbox_hook_linux.h"
 #include "content/public/common/sandbox_init.h"
 #include "services/service_manager/sandbox/linux/sandbox_linux.h"
@@ -111,7 +111,7 @@ namespace content {
 
 namespace {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread*,
                        const gpu::GPUInfo*,
                        const gpu::GpuPreferences&);
@@ -172,7 +172,7 @@ class ContentSandboxHelper : public gpu::GpuSandboxHel
   bool EnsureSandboxInitialized(gpu::GpuWatchdogThread* watchdog_thread,
                                 const gpu::GPUInfo* gpu_info,
                                 const gpu::GpuPreferences& gpu_prefs) override {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
     return StartSandboxLinux(watchdog_thread, gpu_info, gpu_prefs);
 #elif defined(OS_WIN)
     return StartSandboxWindows(sandbox_info_);
@@ -367,7 +367,7 @@ int GpuMain(const MainFunctionParams& parameters) {
 
 namespace {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread* watchdog_thread,
                        const gpu::GPUInfo* gpu_info,
                        const gpu::GpuPreferences& gpu_prefs) {
@@ -402,7 +402,7 @@ bool StartSandboxLinux(gpu::GpuWatchdogThread* watchdo
 
   return res;
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) && !defined(OS_BSD)
 
 #if defined(OS_WIN)
 bool StartSandboxWindows(const sandbox::SandboxInterfaceInfo* sandbox_info) {

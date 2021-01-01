--- content/gpu/gpu_sandbox_hook_linux.cc.orig	2019-09-10 11:14:02 UTC
+++ content/gpu/gpu_sandbox_hook_linux.cc
@@ -95,8 +95,9 @@ static const char kLibV4lEncPluginPath[] =
     "/usr/lib/libv4l/plugins/libv4l-encplugin.so";
 #endif
 
-constexpr int dlopen_flag = RTLD_NOW | RTLD_GLOBAL | RTLD_NODELETE;
+constexpr int dlopen_flag = RTLD_NOW | RTLD_GLOBAL;
 
+#if !defined(OS_BSD)
 void AddV4L2GpuWhitelist(
     std::vector<BrokerFilePermission>* permissions,
     const service_manager::SandboxSeccompBPF::Options& options) {
@@ -287,8 +288,10 @@ std::vector<BrokerFilePermission> FilePermissionsForGp
   AddStandardGpuWhiteList(&permissions);
   return permissions;
 }
+#endif
 
 void LoadArmGpuLibraries() {
+#if !defined(OS_BSD)
   // Preload the Mali library.
   if (UseChromecastSandboxWhitelist()) {
     for (const char* path : kWhitelistedChromecastPaths) {
@@ -303,6 +306,7 @@ void LoadArmGpuLibraries() {
     // Preload the Tegra V4L2 (video decode acceleration) library.
     dlopen(kLibTegraPath, dlopen_flag);
   }
+#endif
 }
 
 bool LoadAmdGpuLibraries() {
@@ -358,6 +362,7 @@ bool LoadLibrariesForGpu(
   return true;
 }
 
+#if !defined(OS_BSD)
 sandbox::syscall_broker::BrokerCommandSet CommandSetForGPU(
     const service_manager::SandboxLinux::Options& options) {
   sandbox::syscall_broker::BrokerCommandSet command_set;
@@ -378,13 +383,17 @@ bool BrokerProcessPreSandboxHook(
   service_manager::SetProcessTitleFromCommandLine(nullptr);
   return true;
 }
+#endif
 
 }  // namespace
 
 bool GpuProcessPreSandboxHook(service_manager::SandboxLinux::Options options) {
+  NOTIMPLEMENTED();
+#if !defined(OS_BSD)
   service_manager::SandboxLinux::GetInstance()->StartBrokerProcess(
       CommandSetForGPU(options), FilePermissionsForGpu(options),
       base::BindOnce(BrokerProcessPreSandboxHook), options);
+#endif
 
   if (!LoadLibrariesForGpu(options))
     return false;

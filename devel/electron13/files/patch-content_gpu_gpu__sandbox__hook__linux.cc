--- content/gpu/gpu_sandbox_hook_linux.cc.orig	2021-07-15 19:13:39 UTC
+++ content/gpu/gpu_sandbox_hook_linux.cc
@@ -378,6 +378,7 @@ std::vector<BrokerFilePermission> FilePermissionsForGp
 }
 
 void LoadArmGpuLibraries() {
+#if !defined(OS_BSD)
   // Preload the Mali library.
   if (UseChromecastSandboxAllowlist()) {
     for (const char* path : kAllowedChromecastPaths) {
@@ -410,6 +411,7 @@ void LoadArmGpuLibraries() {
         dlopen(driver_paths[i], dlopen_flag);
     }
   }
+#endif
 }
 
 bool LoadAmdGpuLibraries() {

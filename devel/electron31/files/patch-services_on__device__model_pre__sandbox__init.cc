--- services/on_device_model/pre_sandbox_init.cc.orig	2024-06-18 21:43:38 UTC
+++ services/on_device_model/pre_sandbox_init.cc
@@ -14,7 +14,7 @@
 #include "services/on_device_model/ml/chrome_ml.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "gpu/config/gpu_info_collector.h"                    // nogncheck
 #include "third_party/dawn/include/dawn/dawn_proc.h"          // nogncheck
 #include "third_party/dawn/include/dawn/native/DawnNative.h"  // nogncheck
@@ -31,7 +31,7 @@ namespace {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 constexpr uint32_t kVendorIdAMD = 0x1002;
 constexpr uint32_t kVendorIdIntel = 0x8086;
 constexpr uint32_t kVendorIdNVIDIA = 0x10DE;
@@ -80,7 +80,7 @@ bool OnDeviceModelService::PreSandboxInit() {
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Warm any relevant drivers before attempting to bring up the sandbox. For
   // good measure we initialize a device instance for any adapter with an
   // appropriate backend on top of any integrated or discrete GPU.
@@ -116,7 +116,7 @@ bool OnDeviceModelService::PreSandboxInit() {
   return true;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // static
 void OnDeviceModelService::AddSandboxLinuxOptions(
     sandbox::policy::SandboxLinux::Options& options) {

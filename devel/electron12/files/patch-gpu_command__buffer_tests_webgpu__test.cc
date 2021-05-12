--- gpu/command_buffer/tests/webgpu_test.cc.orig	2021-04-14 01:08:50 UTC
+++ gpu/command_buffer/tests/webgpu_test.cc
@@ -51,8 +51,8 @@ bool WebGPUTest::WebGPUSupported() const {
 
 bool WebGPUTest::WebGPUSharedImageSupported() const {
   // Currently WebGPUSharedImage is only implemented on Mac, Linux and Windows
-#if (defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-     defined(OS_WIN)) &&                                             \
+#if (defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
+     defined(OS_WIN)) &&                                                                \
     BUILDFLAG(USE_DAWN)
   return true;
 #else
@@ -67,7 +67,7 @@ void WebGPUTest::SetUp() {
 
   gpu::GpuPreferences gpu_preferences;
   gpu_preferences.enable_webgpu = true;
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && BUILDFLAG(USE_DAWN)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && BUILDFLAG(USE_DAWN)
   gpu_preferences.use_vulkan = gpu::VulkanImplementationName::kNative;
   gpu_preferences.gr_context_type = gpu::GrContextType::kVulkan;
 #elif defined(OS_WIN)

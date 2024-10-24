--- core/rend/vulkan/vulkan_context.cpp.orig	2024-10-21 14:13:00 UTC
+++ core/rend/vulkan/vulkan_context.cpp
@@ -42,6 +42,7 @@ VULKAN_HPP_DEFAULT_DISPATCH_LOADER_DYNAMIC_STORAGE
 #endif
 
 #include <memory>
+#include <set>
 
 void ReInitOSD();
 
@@ -146,7 +147,7 @@ bool VulkanContext::InitInstance(const char** extensio
 #if defined(__ANDROID__) && HOST_CPU == CPU_ARM64
 		vkGetInstanceProcAddr = loadVulkanDriver();
 #else
-		static vk::DynamicLoader dl;
+		static vk::detail::DynamicLoader dl;
 		vkGetInstanceProcAddr = dl.getProcAddress<PFN_vkGetInstanceProcAddr>("vkGetInstanceProcAddr");
 #endif
 		if (vkGetInstanceProcAddr == nullptr) {

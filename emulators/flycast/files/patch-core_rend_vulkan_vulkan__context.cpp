--- core/rend/vulkan/vulkan_context.cpp.orig	2026-01-12 20:26:48 UTC
+++ core/rend/vulkan/vulkan_context.cpp
@@ -148,7 +148,7 @@ bool VulkanContext::InitInstance(const char** extensio
 #if defined(__ANDROID__) && HOST_CPU == CPU_ARM64
 		vkGetInstanceProcAddr = loadVulkanDriver();
 #else
-		static vk::DynamicLoader dl;
+		static vk::detail::DynamicLoader dl;
 		vkGetInstanceProcAddr = dl.getProcAddress<PFN_vkGetInstanceProcAddr>("vkGetInstanceProcAddr");
 #endif
 		if (vkGetInstanceProcAddr == nullptr) {

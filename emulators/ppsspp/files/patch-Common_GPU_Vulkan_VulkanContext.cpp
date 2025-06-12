--- Common/GPU/Vulkan/VulkanContext.cpp.orig	2025-06-11 21:04:20 UTC
+++ Common/GPU/Vulkan/VulkanContext.cpp
@@ -119,7 +119,7 @@ VkResult VulkanContext::CreateInstance(const CreateInf
 	if (vkEnumerateInstanceVersion) {
 		vkEnumerateInstanceVersion(&vulkanInstanceApiVersion_);
 		vulkanInstanceApiVersion_ &= 0xFFFFF000;  // Remove patch version.
-		vulkanInstanceApiVersion_ = std::min(VK_API_VERSION_1_4, vulkanInstanceApiVersion_);
+		vulkanInstanceApiVersion_ = std::min(VK_API_VERSION_1_3, vulkanInstanceApiVersion_);
 		std::string versionString = FormatAPIVersion(vulkanInstanceApiVersion_);
 		INFO_LOG(Log::G3D, "Detected Vulkan API version: %s", versionString.c_str());
 	}

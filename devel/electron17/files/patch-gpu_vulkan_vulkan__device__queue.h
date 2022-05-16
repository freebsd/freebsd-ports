--- gpu/vulkan/vulkan_device_queue.h.orig	2022-05-11 07:16:52 UTC
+++ gpu/vulkan/vulkan_device_queue.h
@@ -153,7 +153,7 @@ class COMPONENT_EXPORT(VULKAN) VulkanDeviceQueue {
 
   bool allow_protected_memory_ = false;
 
-#if defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_BSD)
   VkPhysicalDeviceSamplerYcbcrConversionFeatures
       sampler_ycbcr_conversion_features_{
           VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES};

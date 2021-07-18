--- gpu/vulkan/vulkan_image.h.orig	2021-04-14 01:08:50 UTC
+++ gpu/vulkan/vulkan_image.h
@@ -84,7 +84,7 @@ class COMPONENT_EXPORT(VULKAN) VulkanImage {
       VkImageUsageFlags usage,
       VkImageCreateFlags flags);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   static std::unique_ptr<VulkanImage> CreateWithExternalMemoryAndModifiers(
       VulkanDeviceQueue* device_queue,
       const gfx::Size& size,
@@ -166,7 +166,7 @@ class COMPONENT_EXPORT(VULKAN) VulkanImage {
       VkImageCreateFlags flags,
       VkImageTiling image_tiling);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   bool InitializeWithExternalMemoryAndModifiers(VulkanDeviceQueue* device_queue,
                                                 const gfx::Size& size,
                                                 VkFormat format,

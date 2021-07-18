--- gpu/vulkan/vulkan_image.cc.orig	2021-04-14 01:08:50 UTC
+++ gpu/vulkan/vulkan_image.cc
@@ -320,7 +320,7 @@ bool VulkanImage::InitializeWithExternalMemory(
   };
   format_info_2.pNext = &external_info;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   VkPhysicalDeviceImageDrmFormatModifierInfoEXT modifier_info = {
       .sType =
           VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT,

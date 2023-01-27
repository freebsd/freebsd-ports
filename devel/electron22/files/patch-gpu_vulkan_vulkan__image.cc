--- gpu/vulkan/vulkan_image.cc.orig	2022-02-28 16:54:41 UTC
+++ gpu/vulkan/vulkan_image.cc
@@ -322,7 +322,7 @@ bool VulkanImage::InitializeWithExternalMemory(
 
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   VkPhysicalDeviceImageDrmFormatModifierInfoEXT modifier_info = {
       .sType =
           VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT,

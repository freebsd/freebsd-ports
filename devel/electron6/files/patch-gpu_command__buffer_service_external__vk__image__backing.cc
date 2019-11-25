--- gpu/command_buffer/service/external_vk_image_backing.cc.orig	2019-09-10 11:14:05 UTC
+++ gpu/command_buffer/service/external_vk_image_backing.cc
@@ -26,7 +26,7 @@
 #include "gpu/vulkan/fuchsia/vulkan_fuchsia_ext.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #define GL_HANDLE_TYPE_OPAQUE_FD_EXT 0x9586
 #endif
 
@@ -439,7 +439,7 @@ ExternalVkImageBacking::ProduceGLTexture(SharedImageMa
 #if defined(OS_FUCHSIA)
   NOTIMPLEMENTED_LOG_ONCE();
   return nullptr;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   if (!texture_) {
     VkMemoryGetFdInfoKHR get_fd_info;
     get_fd_info.sType = VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR;
@@ -502,7 +502,7 @@ ExternalVkImageBacking::ProduceGLTexture(SharedImageMa
   }
   return std::make_unique<ExternalVkImageGlRepresentation>(
       manager, this, tracker, texture_, texture_->service_id());
-#else  // !defined(OS_LINUX) && !defined(OS_FUCHSIA)
+#else  // !defined(OS_LINUX) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
 #error Unsupported OS
 #endif
 }

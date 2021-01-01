--- gpu/command_buffer/service/external_vk_image_backing.h.orig	2019-12-12 12:39:44 UTC
+++ gpu/command_buffer/service/external_vk_image_backing.h
@@ -133,7 +133,7 @@ class ExternalVkImageBacking : public SharedImageBacki
                          base::Optional<DawnTextureFormat> dawn_format,
                          base::Optional<uint32_t> memory_type_index);
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Extract file descriptor from image
   int GetMemoryFd(const GrVkImageInfo& image_info);
 #endif

--- gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc.orig	2023-08-10 01:48:44 UTC
+++ gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc
@@ -226,7 +226,7 @@ bool ExternalVkImageBackingFactory::IsSupported(
     return false;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (format.IsLegacyMultiplanar()) {
     // ExternalVkImageBacking doesn't work properly with external sampler
     // multi-planar formats on Linux, see https://crbug.com/1394888.

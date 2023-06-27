--- gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc.orig	2023-05-25 00:41:56 UTC
+++ gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc
@@ -201,7 +201,7 @@ bool ExternalVkImageBackingFactory::IsSupported(
     return false;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (format.IsLegacyMultiplanar()) {
     // ExternalVkImageBacking doesn't work properly with external sampler
     // multi-planar formats on Linux, see https://crbug.com/1394888.

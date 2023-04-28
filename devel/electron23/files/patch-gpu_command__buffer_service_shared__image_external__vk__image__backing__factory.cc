--- gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc.orig	2023-02-01 18:43:20 UTC
+++ gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc
@@ -173,7 +173,7 @@ bool ExternalVkImageBackingFactory::IsSupported(
 
   // TODO: remove it when below formats are converted to multi plane shared
   // image formats.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   switch (format.resource_format()) {
     case viz::YUV_420_BIPLANAR:
     case viz::YUVA_420_TRIPLANAR:

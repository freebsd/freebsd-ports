--- gpu/command_buffer/service/shared_image/gl_texture_image_backing_factory.cc.orig	2022-11-30 08:12:58 UTC
+++ gpu/command_buffer/service/shared_image/gl_texture_image_backing_factory.cc
@@ -164,7 +164,7 @@ bool GLTextureImageBackingFactory::IsSupported(
   // Linux and ChromeOS support WebGPU/Compat on GL. All other platforms
   // do not support WebGPU on GL.
   if (usage & SHARED_IMAGE_USAGE_WEBGPU) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(USE_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(USE_OZONE) || BUILDFLAG(IS_BSD)
     if (use_webgpu_adapter_ != WebGPUAdapterName::kCompat) {
       return false;
     }

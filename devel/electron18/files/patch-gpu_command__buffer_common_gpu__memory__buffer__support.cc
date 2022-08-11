--- gpu/command_buffer/common/gpu_memory_buffer_support.cc.orig	2022-05-19 05:17:42 UTC
+++ gpu/command_buffer/common/gpu_memory_buffer_support.cc
@@ -134,7 +134,7 @@ uint32_t GetPlatformSpecificTextureTarget() {
 #if BUILDFLAG(IS_MAC)
   return macos_specific_texture_target;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return GL_TEXTURE_EXTERNAL_OES;
 #elif BUILDFLAG(IS_FUCHSIA)
   return GL_TEXTURE_2D;
@@ -166,7 +166,7 @@ GPU_EXPORT bool NativeBufferNeedsPlatformSpecificTextu
     gfx::BufferFormat format,
     gfx::BufferPlane plane) {
 #if defined(USE_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Always use GL_TEXTURE_2D as the target for RGB textures.
   // https://crbug.com/916728
   if (format == gfx::BufferFormat::R_8 || format == gfx::BufferFormat::RG_88 ||

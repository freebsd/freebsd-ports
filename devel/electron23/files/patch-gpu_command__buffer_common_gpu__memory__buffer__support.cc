--- gpu/command_buffer/common/gpu_memory_buffer_support.cc.orig	2023-02-01 18:43:20 UTC
+++ gpu/command_buffer/common/gpu_memory_buffer_support.cc
@@ -173,7 +173,7 @@ uint32_t GetPlatformSpecificTextureTarget() {
 #if BUILDFLAG(IS_MAC)
   return macos_specific_texture_target;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return GL_TEXTURE_EXTERNAL_OES;
 #elif BUILDFLAG(IS_FUCHSIA)
   // Fuchsia uses Vulkan.
@@ -206,7 +206,7 @@ GPU_EXPORT bool NativeBufferNeedsPlatformSpecificTextu
     gfx::BufferFormat format,
     gfx::BufferPlane plane) {
 #if BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Always use GL_TEXTURE_2D as the target for RGB textures.
   // https://crbug.com/916728
   if (format == gfx::BufferFormat::R_8 || format == gfx::BufferFormat::RG_88 ||

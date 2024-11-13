--- media/gpu/buffer_validation.cc.orig	2024-02-21 00:20:49 UTC
+++ media/gpu/buffer_validation.cc
@@ -16,7 +16,7 @@
 #include "ui/gfx/geometry/size.h"
 #include "ui/gfx/gpu_memory_buffer.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <drm_fourcc.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -29,7 +29,7 @@ namespace {
 namespace media {
 
 namespace {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #ifndef I915_FORMAT_MOD_4_TILED_MTL_MC_CCS
 // TODO(b/271455200): Remove this definition once drm_fourcc.h contains it.
 /*
@@ -55,7 +55,7 @@ bool GetFileSize(const int fd, size_t* size) {
 }  // namespace
 
 bool GetFileSize(const int fd, size_t* size) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (fd < 0) {
     VLOG(1) << "Invalid file descriptor";
     return false;
@@ -109,14 +109,14 @@ bool VerifyGpuMemoryBufferHandle(
     VLOG(1) << "Unsupported: " << pixel_format;
     return false;
   }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   const uint64_t modifier = gmb_handle.native_pixmap_handle.modifier;
   const bool is_intel_media_compressed_buffer =
       IsIntelMediaCompressedModifier(modifier);
   const bool is_intel_media_compression_enabled =
 #if BUILDFLAG(IS_CHROMEOS)
       base::FeatureList::IsEnabled(features::kEnableIntelMediaCompression);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       false;
 #endif
 

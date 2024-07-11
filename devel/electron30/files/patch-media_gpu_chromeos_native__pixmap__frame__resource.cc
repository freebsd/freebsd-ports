--- media/gpu/chromeos/native_pixmap_frame_resource.cc.orig	2024-04-15 20:34:01 UTC
+++ media/gpu/chromeos/native_pixmap_frame_resource.cc
@@ -166,7 +166,7 @@ scoped_refptr<NativePixmapFrameResource> NativePixmapF
   const bool is_intel_media_compression_enabled =
 #if BUILDFLAG(IS_CHROMEOS)
       base::FeatureList::IsEnabled(features::kEnableIntelMediaCompression);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       false;
 #endif
   CHECK(!is_intel_media_compressed_buffer ||

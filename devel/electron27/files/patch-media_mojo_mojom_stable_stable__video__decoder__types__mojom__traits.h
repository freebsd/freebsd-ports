--- media/mojo/mojom/stable/stable_video_decoder_types_mojom_traits.h.orig	2023-10-19 19:58:27 UTC
+++ media/mojo/mojom/stable/stable_video_decoder_types_mojom_traits.h
@@ -693,7 +693,7 @@ struct StructTraits<media::stable::mojom::NativeGpuMem
   static const gfx::GpuMemoryBufferId& id(
       const gfx::GpuMemoryBufferHandle& input);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static gfx::NativePixmapHandle platform_handle(
       gfx::GpuMemoryBufferHandle& input);
 #else

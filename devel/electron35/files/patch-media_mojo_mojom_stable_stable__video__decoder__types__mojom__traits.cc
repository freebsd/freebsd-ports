--- media/mojo/mojom/stable/stable_video_decoder_types_mojom_traits.cc.orig	2025-03-24 20:50:14 UTC
+++ media/mojo/mojom/stable/stable_video_decoder_types_mojom_traits.cc
@@ -861,7 +861,7 @@ const gfx::GpuMemoryBufferId& StructTraits<
   return input.id;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // static
 gfx::NativePixmapHandle StructTraits<
     media::stable::mojom::NativeGpuMemoryBufferHandleDataView,
@@ -882,7 +882,7 @@ bool StructTraits<media::stable::mojom::NativeGpuMemor
 
   output->type = gfx::NATIVE_PIXMAP;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!data.ReadPlatformHandle(&output->native_pixmap_handle))
     return false;
   return true;

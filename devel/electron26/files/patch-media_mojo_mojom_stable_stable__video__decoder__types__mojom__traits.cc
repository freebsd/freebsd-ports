--- media/mojo/mojom/stable/stable_video_decoder_types_mojom_traits.cc.orig	2023-08-10 01:48:46 UTC
+++ media/mojo/mojom/stable/stable_video_decoder_types_mojom_traits.cc
@@ -730,7 +730,7 @@ const gfx::GpuMemoryBufferId& StructTraits<
   return input.id;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // static
 gfx::NativePixmapHandle StructTraits<
     media::stable::mojom::NativeGpuMemoryBufferHandleDataView,
@@ -751,7 +751,7 @@ bool StructTraits<media::stable::mojom::NativeGpuMemor
 
   output->type = gfx::NATIVE_PIXMAP;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!data.ReadPlatformHandle(&output->native_pixmap_handle))
     return false;
   return true;

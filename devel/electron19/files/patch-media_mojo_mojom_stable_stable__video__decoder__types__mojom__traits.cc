--- media/mojo/mojom/stable/stable_video_decoder_types_mojom_traits.cc.orig	2022-05-25 04:01:04 UTC
+++ media/mojo/mojom/stable/stable_video_decoder_types_mojom_traits.cc
@@ -42,7 +42,7 @@ media::stable::mojom::VideoFrameDataPtr MakeVideoFrame
   gfx::GpuMemoryBufferHandle gpu_memory_buffer_handle =
       input->GetGpuMemoryBuffer()->CloneHandle();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   CHECK_EQ(gpu_memory_buffer_handle.type, gfx::NATIVE_PIXMAP);
   CHECK(!gpu_memory_buffer_handle.native_pixmap_handle.planes.empty());
 #else
@@ -749,7 +749,7 @@ const gfx::GpuMemoryBufferId& StructTraits<
   return input.id;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // static
 gfx::NativePixmapHandle StructTraits<
     media::stable::mojom::NativeGpuMemoryBufferHandleDataView,
@@ -770,7 +770,7 @@ bool StructTraits<media::stable::mojom::NativeGpuMemor
 
   output->type = gfx::NATIVE_PIXMAP;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!data.ReadPlatformHandle(&output->native_pixmap_handle))
     return false;
   return true;

--- media/video/mappable_shared_image_video_frame_pool.cc.orig	2026-03-13 16:54:03 UTC
+++ media/video/mappable_shared_image_video_frame_pool.cc
@@ -685,7 +685,7 @@ void MappableSharedImageVideoFramePool::PoolImpl::Crea
   }
 
   bool is_software_backed_video_frame = !video_frame->HasSharedImage();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 
@@ -1093,7 +1093,7 @@ scoped_refptr<VideoFrame> MappableSharedImageVideoFram
       media::IOSurfaceIsWebGPUCompatible(handle.io_surface().get());
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // TOOD(crbug.com/425634684): Check for webgpu support from
   // SharedImageCapabilities, once this metadata is compatible.
   is_webgpu_compatible =

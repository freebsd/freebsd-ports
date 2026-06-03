--- media/video/renderable_mappable_shared_image_video_frame_pool.cc.orig	2026-03-21 03:23:28 UTC
+++ media/video/renderable_mappable_shared_image_video_frame_pool.cc
@@ -198,7 +198,7 @@ bool FrameResources::Initialize(VideoPixelFormat forma
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
   buffer_usage = gfx::BufferUsage::SCANOUT_VEA_CPU_READ;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, GBM_BO_USE_LINEAR (implied by SCANOUT_CPU_READ_WRITE) can
   // prevent GPU rendering on some drivers, notably NVIDIA's GBM driver,
   // because it disables GBM_BO_USE_RENDERING. Use SCANOUT instead if

--- media/video/gpu_memory_buffer_video_frame_pool.cc.orig	2022-11-30 08:12:58 UTC
+++ media/video/gpu_memory_buffer_video_frame_pool.cc
@@ -732,7 +732,7 @@ void GpuMemoryBufferVideoFramePool::PoolImpl::CreateHa
   }
 
   bool is_software_backed_video_frame = !video_frame->HasTextures();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 
@@ -1160,7 +1160,7 @@ scoped_refptr<VideoFrame> GpuMemoryBufferVideoFramePoo
     is_webgpu_compatible = (gpu_memory_buffer != nullptr);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     is_webgpu_compatible = (gpu_memory_buffer != nullptr);
     if (is_webgpu_compatible) {
       is_webgpu_compatible &=
@@ -1179,7 +1179,7 @@ scoped_refptr<VideoFrame> GpuMemoryBufferVideoFramePoo
                        gpu::SHARED_IMAGE_USAGE_DISPLAY_READ |
                        gpu::SHARED_IMAGE_USAGE_SCANOUT;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       // TODO(crbug.com/1241537): Always add the flag once the
       // OzoneImageBacking is by default turned on.
       if (base::CommandLine::ForCurrentProcess()->HasSwitch(

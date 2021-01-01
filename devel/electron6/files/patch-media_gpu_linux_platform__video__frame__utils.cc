--- media/gpu/linux/platform_video_frame_utils.cc.orig	2019-09-10 11:14:08 UTC
+++ media/gpu/linux/platform_video_frame_utils.cc
@@ -107,7 +107,7 @@ gfx::GpuMemoryBufferHandle CreateGpuMemoryBufferHandle
   DCHECK(video_frame);
 
   gfx::GpuMemoryBufferHandle handle;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   handle.type = gfx::NATIVE_PIXMAP;
 
   std::vector<base::ScopedFD> duped_fds =
@@ -126,7 +126,7 @@ gfx::GpuMemoryBufferHandle CreateGpuMemoryBufferHandle
   }
 #else
   NOTREACHED();
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
   return handle;
 }
 

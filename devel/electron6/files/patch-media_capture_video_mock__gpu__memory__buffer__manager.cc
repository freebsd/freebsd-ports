--- media/capture/video/mock_gpu_memory_buffer_manager.cc.orig	2019-09-10 10:42:40 UTC
+++ media/capture/video/mock_gpu_memory_buffer_manager.cc
@@ -115,7 +115,7 @@ class FakeGpuMemoryBuffer : public gfx::GpuMemoryBuffe
     gfx::GpuMemoryBufferHandle handle;
     handle.type = gfx::NATIVE_PIXMAP;
     handle.id = handle_.id;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     handle.native_pixmap_handle =
         gfx::CloneHandleForIPC(handle_.native_pixmap_handle);
 #endif

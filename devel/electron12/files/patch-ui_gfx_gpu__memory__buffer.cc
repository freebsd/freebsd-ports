--- ui/gfx/gpu_memory_buffer.cc.orig	2021-04-14 01:09:39 UTC
+++ ui/gfx/gpu_memory_buffer.cc
@@ -34,7 +34,7 @@ GpuMemoryBufferHandle GpuMemoryBufferHandle::Clone() c
   handle.region = region.Duplicate();
   handle.offset = offset;
   handle.stride = stride;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
   handle.native_pixmap_handle = CloneHandleForIPC(native_pixmap_handle);
 #elif defined(OS_MAC)
   handle.io_surface = io_surface;

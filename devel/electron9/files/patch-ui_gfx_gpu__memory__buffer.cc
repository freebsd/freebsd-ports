--- ui/gfx/gpu_memory_buffer.cc.orig	2020-05-26 07:49:14 UTC
+++ ui/gfx/gpu_memory_buffer.cc
@@ -34,7 +34,7 @@ GpuMemoryBufferHandle GpuMemoryBufferHandle::Clone() c
   handle.region = region.Duplicate();
   handle.offset = offset;
   handle.stride = stride;
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   handle.native_pixmap_handle = CloneHandleForIPC(native_pixmap_handle);
 #elif defined(OS_MACOSX) && !defined(OS_IOS)
   NOTIMPLEMENTED();

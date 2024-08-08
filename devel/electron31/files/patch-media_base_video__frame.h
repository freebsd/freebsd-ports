--- media/base/video_frame.h.orig	2024-06-18 21:43:35 UTC
+++ media/base/video_frame.h
@@ -45,7 +45,7 @@
 #include "base/apple/scoped_cftyperef.h"
 #endif  // BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/files/scoped_file.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -111,7 +111,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
     STORAGE_UNOWNED_MEMORY = 2,  // External, non owned data pointers.
     STORAGE_OWNED_MEMORY = 3,  // VideoFrame has allocated its own data buffer.
     STORAGE_SHMEM = 4,         // Backed by read-only shared memory.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // TODO(mcasas): Consider turning this type into STORAGE_NATIVE
     // based on the idea of using this same enum value for both DMA
     // buffers on Linux and CVPixelBuffers on Mac (which currently use
@@ -341,7 +341,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
       ReleaseMailboxAndGpuMemoryBufferCB mailbox_holder_and_gmb_release_cb,
       base::TimeDelta timestamp);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Wraps provided dmabufs
   // (https://www.kernel.org/doc/html/latest/driver-api/dma-buf.html) with a
   // VideoFrame. The frame will take ownership of |dmabuf_fds|, and will
@@ -650,7 +650,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
   scoped_refptr<gpu::ClientSharedImage> shared_image(
       size_t texture_index) const;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The number of DmaBufs will be equal or less than the number of planes of
   // the frame. If there are less, this means that the last FD contains the
   // remaining planes. Should be > 0 for STORAGE_DMABUFS.
@@ -886,7 +886,7 @@ class MEDIA_EXPORT VideoFrame : public base::RefCounte
   // GPU memory buffer, if this frame is STORAGE_GPU_MEMORY_BUFFER.
   std::unique_ptr<gfx::GpuMemoryBuffer> gpu_memory_buffer_;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   class DmabufHolder;
 
   // Dmabufs for the frame, used when storage is STORAGE_DMABUFS. Size is either

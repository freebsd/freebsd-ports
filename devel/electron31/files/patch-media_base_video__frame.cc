--- media/base/video_frame.cc.orig	2024-06-18 21:43:35 UTC
+++ media/base/video_frame.cc
@@ -80,7 +80,7 @@ std::string VideoFrame::StorageTypeToString(
       return "OWNED_MEMORY";
     case VideoFrame::STORAGE_SHMEM:
       return "SHMEM";
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case VideoFrame::STORAGE_DMABUFS:
       return "DMABUFS";
 #endif
@@ -95,7 +95,7 @@ bool VideoFrame::IsStorageTypeMappable(VideoFrame::Sto
 // static
 bool VideoFrame::IsStorageTypeMappable(VideoFrame::StorageType storage_type) {
   return
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       // This is not strictly needed but makes explicit that, at VideoFrame
       // level, DmaBufs are not mappable from userspace.
       storage_type != VideoFrame::STORAGE_DMABUFS &&
@@ -306,7 +306,7 @@ static std::optional<VideoFrameLayout> GetDefaultLayou
   return VideoFrameLayout::CreateWithPlanes(format, coded_size, planes);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // This class allows us to embed a vector<ScopedFD> into a scoped_refptr, and
 // thus to have several VideoFrames share the same set of DMABUF FDs.
 class VideoFrame::DmabufHolder
@@ -440,7 +440,7 @@ scoped_refptr<VideoFrame> VideoFrame::CreateFrameForGp
     planes[i].stride = gpu_memory_buffer->stride(i);
   }
   uint64_t modifier = gfx::NativePixmapHandle::kNoModifier;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (gpu_memory_buffer->GetType() == gfx::NATIVE_PIXMAP) {
     const auto gmb_handle = gpu_memory_buffer->CloneHandle();
     if (gmb_handle.is_null() ||
@@ -778,7 +778,7 @@ scoped_refptr<VideoFrame> VideoFrame::WrapExternalGpuM
   return frame;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // static
 scoped_refptr<VideoFrame> VideoFrame::WrapExternalDmabufs(
     const VideoFrameLayout& layout,
@@ -997,7 +997,7 @@ scoped_refptr<VideoFrame> VideoFrame::WrapVideoFrame(
     }
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   DCHECK(frame->dmabuf_fds_);
   // If there are any |dmabuf_fds_| plugged in, we should refer them too.
   wrapping_frame->dmabuf_fds_ = frame->dmabuf_fds_;
@@ -1471,7 +1471,7 @@ scoped_refptr<gpu::ClientSharedImage> VideoFrame::shar
                         : shared_images_[texture_index];
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 size_t VideoFrame::NumDmabufFds() const {
   return dmabuf_fds_->size();
 }
@@ -1588,7 +1588,7 @@ VideoFrame::VideoFrame(const VideoFrameLayout& layout,
       storage_type_(storage_type),
       visible_rect_(Intersection(visible_rect, gfx::Rect(layout.coded_size()))),
       natural_size_(natural_size),
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       dmabuf_fds_(base::MakeRefCounted<DmabufHolder>()),
 #endif
       timestamp_(timestamp),

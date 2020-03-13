--- media/mojo/mojom/video_frame_mojom_traits.cc.orig	2019-12-12 12:39:50 UTC
+++ media/mojo/mojom/video_frame_mojom_traits.cc
@@ -52,7 +52,7 @@ media::mojom::VideoFrameDataPtr MakeVideoFrameData(
             mojo_frame->PlaneOffset(media::VideoFrame::kVPlane)));
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (input->storage_type() == media::VideoFrame::STORAGE_DMABUFS) {
     std::vector<mojo::ScopedHandle> dmabuf_fds;
 
@@ -145,7 +145,7 @@ bool StructTraits<media::mojom::VideoFrameDataView,
         shared_buffer_data.u_offset(), shared_buffer_data.v_offset(),
         shared_buffer_data.y_stride(), shared_buffer_data.u_stride(),
         shared_buffer_data.v_stride(), timestamp);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (data.is_dmabuf_data()) {
     media::mojom::DmabufVideoFrameDataDataView dmabuf_data;
     data.GetDmabufDataDataView(&dmabuf_data);

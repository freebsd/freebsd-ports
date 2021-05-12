--- media/mojo/mojom/video_frame_mojom_traits.cc.orig	2021-04-14 01:08:51 UTC
+++ media/mojo/mojom/video_frame_mojom_traits.cc
@@ -21,9 +21,9 @@
 #include "ui/gfx/mojom/color_space_mojom_traits.h"
 #include "ui/gfx/mojom/hdr_metadata_mojom_traits.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/posix/eintr_wrapper.h"
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 namespace mojo {
 
@@ -63,7 +63,7 @@ media::mojom::VideoFrameDataPtr MakeVideoFrameData(
             std::move(offsets)));
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (input->storage_type() == media::VideoFrame::STORAGE_DMABUFS) {
     std::vector<mojo::PlatformHandle> dmabuf_fds;
 
@@ -166,7 +166,7 @@ bool StructTraits<media::mojom::VideoFrameDataView,
         shared_buffer_data.TakeFrameData(),
         shared_buffer_data.frame_data_size(), std::move(offsets),
         std::move(strides), timestamp);
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   } else if (data.is_dmabuf_data()) {
     media::mojom::DmabufVideoFrameDataDataView dmabuf_data;
     data.GetDmabufDataDataView(&dmabuf_data);

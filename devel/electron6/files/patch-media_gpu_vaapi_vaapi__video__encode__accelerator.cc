--- media/gpu/vaapi/vaapi_video_encode_accelerator.cc.orig	2019-09-10 11:14:08 UTC
+++ media/gpu/vaapi/vaapi_video_encode_accelerator.cc
@@ -41,7 +41,7 @@
 #include "media/gpu/vp8_reference_frame_vector.h"
 #include "media/gpu/vp9_reference_frame_vector.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "media/gpu/linux/platform_video_frame_utils.h"
 #endif
 
@@ -558,7 +558,7 @@ scoped_refptr<VaapiEncodeJob> VaapiVideoEncodeAccelera
         vaapi_wrapper_, MakeGLContextCurrentCallback(), BindGLImageCallback(),
         PictureBuffer(kDummyPictureBufferId, frame->coded_size()));
     gfx::GpuMemoryBufferHandle gmb_handle;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     gmb_handle = CreateGpuMemoryBufferHandle(frame.get());
 #endif
     if (gmb_handle.is_null()) {

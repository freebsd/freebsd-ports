--- third_party/blink/renderer/platform/video_capture/video_capture_impl.cc.orig	2023-10-19 19:58:33 UTC
+++ third_party/blink/renderer/platform/video_capture/video_capture_impl.cc
@@ -621,7 +621,7 @@ bool VideoCaptureImpl::VideoFrameBufferPreparer::BindV
   }
 
   const unsigned texture_target =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // Explicitly set GL_TEXTURE_EXTERNAL_OES as the
       // `media::VideoFrame::RequiresExternalSampler()` requires it for NV12
       // format, while the `ImageTextureTarget()` will return GL_TEXTURE_2D.

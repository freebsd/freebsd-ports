--- media/gpu/chromeos/libyuv_image_processor_backend.cc.orig	2024-06-18 21:43:35 UTC
+++ media/gpu/chromeos/libyuv_image_processor_backend.cc
@@ -48,7 +48,7 @@ static constexpr struct {
 #define CONV(in, out, trans, result) \
   {Fourcc::in, Fourcc::out, Transform::trans, SupportResult::result}
     // Conversion.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     CONV(NV12, AR24, kConversion, Supported),
 #endif
     CONV(NV12, NV12, kConversion, Supported),
@@ -415,7 +415,7 @@ int LibYUVImageProcessorBackend::DoConversion(const Fr
           fr->GetWritableVisibleData(VideoFrame::Plane::kUV)), \
       fr->stride(VideoFrame::Plane::kUV)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define ARGB_DATA(fr)                                   \
   fr->GetWritableVisibleData(VideoFrame::Plane::kARGB), \
       fr->stride(VideoFrame::Plane::kARGB)
@@ -577,7 +577,7 @@ int LibYUVImageProcessorBackend::DoConversion(const Fr
     }
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (output->format() == PIXEL_FORMAT_ARGB) {
     if (input_config_.fourcc == Fourcc(Fourcc::NV12)) {
       return LIBYUV_FUNC(NV12ToARGB, Y_UV_DATA(input),

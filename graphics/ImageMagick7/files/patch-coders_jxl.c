https://github.com/ImageMagick/ImageMagick/commit/9db502e6a70c

--- coders/jxl.c.orig	2023-02-12 15:55:38 UTC
+++ coders/jxl.c
@@ -444,8 +444,13 @@ static Image *ReadJXLImage(const ImageInfo *image_info
           *profile;
 
         JXLSetFormat(image,&pixel_format,exception);
+#if JPEGXL_NUMERIC_VERSION >= JPEGXL_COMPUTE_NUMERIC_VERSION(0,9,0)
+        jxl_status=JxlDecoderGetColorAsEncodedProfile(jxl_info,
+          JXL_COLOR_PROFILE_TARGET_DATA,&color_encoding);
+#else
         jxl_status=JxlDecoderGetColorAsEncodedProfile(jxl_info,&pixel_format,
           JXL_COLOR_PROFILE_TARGET_DATA,&color_encoding);
+#endif
         if (jxl_status == JXL_DEC_SUCCESS)
           {
             if (color_encoding.transfer_function == JXL_TRANSFER_FUNCTION_LINEAR)
@@ -460,14 +465,25 @@ static Image *ReadJXLImage(const ImageInfo *image_info
         else
           if (jxl_status != JXL_DEC_ERROR)
             break;
+#if JPEGXL_NUMERIC_VERSION >= JPEGXL_COMPUTE_NUMERIC_VERSION(0,9,0)
+        jxl_status=JxlDecoderGetICCProfileSize(jxl_info,
+          JXL_COLOR_PROFILE_TARGET_ORIGINAL,&profile_size);
+#else
         jxl_status=JxlDecoderGetICCProfileSize(jxl_info,&pixel_format,
           JXL_COLOR_PROFILE_TARGET_ORIGINAL,&profile_size);
+#endif
         if (jxl_status != JXL_DEC_SUCCESS)
           break;
         profile=AcquireStringInfo(profile_size);
+#if JPEGXL_NUMERIC_VERSION >= JPEGXL_COMPUTE_NUMERIC_VERSION(0,9,0)
+        jxl_status=JxlDecoderGetColorAsICCProfile(jxl_info,
+          JXL_COLOR_PROFILE_TARGET_ORIGINAL,GetStringInfoDatum(profile),
+          profile_size);
+#else
         jxl_status=JxlDecoderGetColorAsICCProfile(jxl_info,&pixel_format,
           JXL_COLOR_PROFILE_TARGET_ORIGINAL,GetStringInfoDatum(profile),
           profile_size);
+#endif
         (void) SetImageProfile(image,"icc",profile,exception);
         profile=DestroyStringInfo(profile);
         if (jxl_status == JXL_DEC_SUCCESS)

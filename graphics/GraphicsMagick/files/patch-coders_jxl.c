https://sourceforge.net/p/graphicsmagick/code/ci/43bc74dd0c13/

--- coders/jxl.c.orig	2023-01-14 15:40:53 UTC
+++ coders/jxl.c
@@ -631,8 +631,12 @@ static Image *ReadJXLImage(const ImageInfo *image_info
             JxlColorEncoding
               color_encoding;
 
-            status=JxlDecoderGetColorAsEncodedProfile(jxl_decoder,&pixel_format,
-                                                      JXL_COLOR_PROFILE_TARGET_DATA,&color_encoding);
+            status=JxlDecoderGetColorAsEncodedProfile(jxl_decoder,
+#if JPEGXL_NUMERIC_VERSION < JPEGXL_COMPUTE_NUMERIC_VERSION(0,9,0)
+                                                      &pixel_format,
+#endif /* if JPEGXL_NUMERIC_VERSION < JPEGXL_COMPUTE_NUMERIC_VERSION(0,9,0) */
+                                                      JXL_COLOR_PROFILE_TARGET_DATA,
+                                                      &color_encoding);
             if (status == JXL_DEC_ERROR)
               {
                 status=JXL_DEC_SUCCESS;
@@ -733,8 +737,12 @@ static Image *ReadJXLImage(const ImageInfo *image_info
               size_t
                 profile_size;
 
-              if (JxlDecoderGetICCProfileSize(jxl_decoder,&pixel_format,
-                                              JXL_COLOR_PROFILE_TARGET_ORIGINAL,&profile_size)
+              if (JxlDecoderGetICCProfileSize(jxl_decoder,
+#if JPEGXL_NUMERIC_VERSION < JPEGXL_COMPUTE_NUMERIC_VERSION(0,9,0)
+                                              &pixel_format,
+#endif /* if JPEGXL_NUMERIC_VERSION < JPEGXL_COMPUTE_NUMERIC_VERSION(0,9,0) */
+                                              JXL_COLOR_PROFILE_TARGET_ORIGINAL,
+                                              &profile_size)
                   == JXL_DEC_SUCCESS)
                 {
                   unsigned char
@@ -743,10 +751,14 @@ static Image *ReadJXLImage(const ImageInfo *image_info
                   if ((profile=MagickAllocateResourceLimitedMemory(unsigned char *,profile_size))
                       != NULL)
                     {
-                      if (JxlDecoderGetColorAsICCProfile(jxl_decoder,&pixel_format,
+                      if (JxlDecoderGetColorAsICCProfile(jxl_decoder,
+#if JPEGXL_NUMERIC_VERSION < JPEGXL_COMPUTE_NUMERIC_VERSION(0,9,0)
+                                                         &pixel_format,
+#endif /* if JPEGXL_NUMERIC_VERSION < JPEGXL_COMPUTE_NUMERIC_VERSION(0,9,0) */
                                                          JXL_COLOR_PROFILE_TARGET_ORIGINAL,
                                                          profile,
-                                                         profile_size) == JXL_DEC_SUCCESS)
+                                                         profile_size)
+                          == JXL_DEC_SUCCESS)
                         {
                           (void) SetImageProfile(image,"ICM",profile,profile_size);
                         }
@@ -1268,8 +1280,11 @@ static unsigned int WriteJXLImage(const ImageInfo *ima
       /* TODO better error codes */
       if (jxl_status == JXL_ENC_ERROR)
         ThrowJXLWriterException(CoderError,NoDataReturned,image);
+#if JPEGXL_NUMERIC_VERSION < JPEGXL_COMPUTE_NUMERIC_VERSION(0,9,0)
+      /* JXL_ENC_NOT_SUPPORTED was removed for 0.9.0, although API docs still mention it. */
       else if (jxl_status == JXL_ENC_NOT_SUPPORTED)
         ThrowJXLWriterException(CoderError,UnsupportedBitsPerSample,image);
+#endif /* if JPEGXL_NUMERIC_VERSION < JPEGXL_COMPUTE_NUMERIC_VERSION(0,9,0) */
       else
         ThrowJXLWriterException(CoderFatalError,Default,image);
     }

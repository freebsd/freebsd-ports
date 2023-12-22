https://gitlab.gnome.org/GNOME/gimp/-/commit/a4f02398188b

--- plug-ins/common/file-jpegxl.c.orig	2023-02-21 19:56:19 UTC
+++ plug-ins/common/file-jpegxl.c
@@ -335,7 +335,10 @@ load_image (const gchar *filename,
   result_size = channel_depth * pixel_format.num_channels
                 * (size_t) basicinfo.xsize * (size_t) basicinfo.ysize;
 
-  if (JxlDecoderGetColorAsEncodedProfile (decoder, &pixel_format,
+  if (JxlDecoderGetColorAsEncodedProfile (decoder,
+#if JPEGXL_NUMERIC_VERSION < JPEGXL_COMPUTE_NUMERIC_VERSION(0,9,0)
+                                          &pixel_format,
+#endif
                                           JXL_COLOR_PROFILE_TARGET_DATA,
                                           &color_encoding) == JXL_DEC_SUCCESS)
     {
@@ -379,7 +382,10 @@ load_image (const gchar *filename,
 
   if (! profile)
     {
-      if (JxlDecoderGetICCProfileSize (decoder, &pixel_format,
+      if (JxlDecoderGetICCProfileSize (decoder,
+#if JPEGXL_NUMERIC_VERSION < JPEGXL_COMPUTE_NUMERIC_VERSION(0,9,0)
+                                       &pixel_format,
+#endif
                                        JXL_COLOR_PROFILE_TARGET_DATA,
                                        &icc_size) == JXL_DEC_SUCCESS)
         {
@@ -387,7 +393,11 @@ load_image (const gchar *filename,
             {
               gpointer raw_icc_profile = g_malloc (icc_size);
 
-              if (JxlDecoderGetColorAsICCProfile (decoder, &pixel_format, JXL_COLOR_PROFILE_TARGET_DATA,
+              if (JxlDecoderGetColorAsICCProfile (decoder,
+#if JPEGXL_NUMERIC_VERSION < JPEGXL_COMPUTE_NUMERIC_VERSION(0,9,0)
+                                                  &pixel_format,
+#endif
+                                                  JXL_COLOR_PROFILE_TARGET_DATA,
                                                   raw_icc_profile, icc_size)
                   == JXL_DEC_SUCCESS)
                 {

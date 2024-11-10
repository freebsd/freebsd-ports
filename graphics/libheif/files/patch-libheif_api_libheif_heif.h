--- libheif/api/libheif/heif.h.orig	2024-11-01 10:56:56 UTC
+++ libheif/api/libheif/heif.h
@@ -2363,7 +2363,7 @@ struct heif_encoding_options
 
   // Set this to the NCLX parameters to be used in the output image or set to NULL
   // when the same parameters as in the input image should be used.
-  const struct heif_color_profile_nclx* output_nclx_profile;
+  struct heif_color_profile_nclx* output_nclx_profile;
 
   uint8_t macOS_compatibility_workaround_no_nclx_profile;
 

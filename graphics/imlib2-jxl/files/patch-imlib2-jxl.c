https://github.com/alistair7/imlib2-jxl/commit/3888defd345f
https://github.com/alistair7/imlib2-jxl/commit/06a3b71e4d13
https://github.com/alistair7/imlib2-jxl/commit/de2b38f5f34f

--- imlib2-jxl.c.orig	2022-01-20 21:53:36 UTC
+++ imlib2-jxl.c
@@ -402,7 +402,7 @@ char load(ImlibImage *im, ImlibProgressFunction progre
              * extract an ICC profile and save it for later. */
 
             JxlColorEncoding color_enc;
-            if(JxlDecoderGetColorAsEncodedProfile(dec, &pixel_format, JXL_COLOR_PROFILE_TARGET_DATA, &color_enc) == JXL_DEC_SUCCESS)
+            if(JxlDecoderGetColorAsEncodedProfile(dec, JXL_COLOR_PROFILE_TARGET_DATA, &color_enc) == JXL_DEC_SUCCESS)
             {
                 if(color_enc.color_space == JXL_COLOR_SPACE_RGB && color_enc.transfer_function == JXL_TRANSFER_FUNCTION_SRGB)
                 {
@@ -412,7 +412,7 @@ char load(ImlibImage *im, ImlibProgressFunction progre
                 }
             }
 
-            if(JxlDecoderGetICCProfileSize(dec, &pixel_format, JXL_COLOR_PROFILE_TARGET_DATA, &icc_size) != JXL_DEC_SUCCESS)
+            if(JxlDecoderGetICCProfileSize(dec, JXL_COLOR_PROFILE_TARGET_DATA, &icc_size) != JXL_DEC_SUCCESS)
             {
                 icc_size = 0;
                 break;
@@ -420,7 +420,7 @@ char load(ImlibImage *im, ImlibProgressFunction progre
             if(!(icc_blob = malloc(icc_size)))
                 RETURN_ERR("Failed to allocate %zu B for ICC profile", icc_size);
 
-            if(JxlDecoderGetColorAsICCProfile(dec, &pixel_format, JXL_COLOR_PROFILE_TARGET_DATA, icc_blob, icc_size) != JXL_DEC_SUCCESS)
+            if(JxlDecoderGetColorAsICCProfile(dec, JXL_COLOR_PROFILE_TARGET_DATA, icc_blob, icc_size) != JXL_DEC_SUCCESS)
                 icc_size = 0;
 
             break;
@@ -596,9 +596,9 @@ char save(ImlibImage *im, ImlibProgressFunction progre
     if(JxlEncoderSetParallelRunner(enc, JxlThreadParallelRunner, runner) != JXL_ENC_SUCCESS)
         RETURN_ERR("Failed in JxlEncoderSetParallelRunner");
 
-    JxlEncoderOptions *opts;
-    if(!(opts = JxlEncoderOptionsCreate(enc, NULL)))
-        RETURN_ERR("Failed in JxlEncoderOptionsCreate");
+    JxlEncoderFrameSettings *opts;
+    if(!(opts = JxlEncoderFrameSettingsCreate(enc, NULL)))
+        RETURN_ERR("Failed in JxlEncoderFrameSettingsCreate");
 
     JxlPixelFormat pixel_format = { .align = 0, .data_type = JXL_TYPE_UINT8, .num_channels = 4, .endianness = JXL_NATIVE_ENDIAN};
 
@@ -633,14 +633,14 @@ char save(ImlibImage *im, ImlibProgressFunction progre
             quality = max_quality;
 
         // Transform quality 0-99 to distance 15-0
-        if(JxlEncoderOptionsSetDistance(opts, 15 - (quality * 15/(float)max_quality)) != JXL_ENC_SUCCESS)
-            RETURN_ERR("Failed in JxlEncoderOptionsSetDistance: %.1f", 15 - (quality * 15/(float)max_quality));
+        if(JxlEncoderSetFrameDistance(opts, 15 - (quality * 15/(float)max_quality)) != JXL_ENC_SUCCESS)
+            RETURN_ERR("Failed in JxlEncoderSetFrameDistance: %.1f", 15 - (quality * 15/(float)max_quality));
 
         // If quality is maxed out, explicity enable lossless mode
         if(quality == max_quality)
         {
-            if(JxlEncoderOptionsSetLossless(opts, 1) != JXL_ENC_SUCCESS)
-                RETURN_ERR("Failed in JxlEncoderOptionsSetLossless");
+            if(JxlEncoderSetFrameLossless(opts, JXL_TRUE) != JXL_ENC_SUCCESS)
+                RETURN_ERR("Failed in JxlEncoderSetFrameLossless");
         }
 
     }
@@ -659,8 +659,8 @@ char save(ImlibImage *im, ImlibProgressFunction progre
         // Transform compression 0-9 to effort 3-9
         compression = 3 + (int)roundf(compression * 6/(float)max_compression);
 
-        if(JxlEncoderOptionsSetEffort(opts, compression) != JXL_ENC_SUCCESS)
-            RETURN_ERR("Failed in JxlEncoderOptionsSetEffort: %d", compression);
+        if(JxlEncoderFrameSettingsSetOption(opts, JXL_ENC_FRAME_SETTING_EFFORT, compression) != JXL_ENC_SUCCESS)
+            RETURN_ERR("Failed in JxlEncoderFrameSettingsSetOption(JXL_ENC_FRAME_SETTING_EFFORT, %d)", compression);
     }
 
     const size_t pixels_size = 4 * im->w * im->h;

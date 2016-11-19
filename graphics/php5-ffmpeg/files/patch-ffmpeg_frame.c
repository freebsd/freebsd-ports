--- ffmpeg_frame.c.orig	2014-07-23 17:57:32 UTC
+++ ffmpeg_frame.c
@@ -499,7 +499,7 @@ int _php_resample_frame(ff_frame_context
     }
 
     /* convert to PIX_FMT_YUV420P required for resampling */
-    _php_convert_frame(ff_frame, PIX_FMT_YUV420P);
+    _php_convert_frame(ff_frame, AV_PIX_FMT_YUV420P);
 
     img_resample_ctx = img_resample_full_init(
             wanted_width, wanted_height,
@@ -511,7 +511,7 @@ int _php_resample_frame(ff_frame_context
     }
 
     resampled_frame = avcodec_alloc_frame();
-    avpicture_alloc((AVPicture*)resampled_frame, PIX_FMT_YUV420P, 
+    avpicture_alloc((AVPicture*)resampled_frame, AV_PIX_FMT_YUV420P, 
             wanted_width, wanted_height);
 
     img_resample(img_resample_ctx, (AVPicture*)resampled_frame, 

--- ffmpeg_frame.c.orig	2014-07-23 17:57:32 UTC
+++ ffmpeg_frame.c
@@ -211,7 +211,7 @@ int _php_convert_frame(ff_frame_context 
         return 0; // NOP
     }
 
-    dst_frame = avcodec_alloc_frame();
+    dst_frame = av_frame_alloc();
     avpicture_alloc((AVPicture*)dst_frame, dst_fmt, ff_frame->width,
             ff_frame->height);
 
@@ -400,7 +400,7 @@ FFMPEG_PHP_METHOD(ffmpeg_frame, ffmpeg_f
             height = gdImageSY(gd_img);
 
             /* create a an av_frame and allocate space for it */
-            frame = avcodec_alloc_frame();
+            frame = av_frame_alloc();
             avpicture_alloc((AVPicture*)frame, FFMPEG_PHP_FFMPEG_RGB_PIX_FORMAT, width, height);
 
             /* copy the gd image to the av_frame */
@@ -499,7 +499,7 @@ int _php_resample_frame(ff_frame_context
     }
 
     /* convert to PIX_FMT_YUV420P required for resampling */
-    _php_convert_frame(ff_frame, PIX_FMT_YUV420P);
+    _php_convert_frame(ff_frame, AV_PIX_FMT_YUV420P);
 
     img_resample_ctx = img_resample_full_init(
             wanted_width, wanted_height,
@@ -510,8 +510,8 @@ int _php_resample_frame(ff_frame_context
         return -1;
     }
 
-    resampled_frame = avcodec_alloc_frame();
-    avpicture_alloc((AVPicture*)resampled_frame, PIX_FMT_YUV420P, 
+    resampled_frame = av_frame_alloc();
+    avpicture_alloc((AVPicture*)resampled_frame, AV_PIX_FMT_YUV420P, 
             wanted_width, wanted_height);
 
     img_resample(img_resample_ctx, (AVPicture*)resampled_frame, 

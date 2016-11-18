--- ffmpeg_tools.c.orig	2014-07-23 17:57:32 UTC
+++ ffmpeg_tools.c
@@ -98,8 +98,8 @@ ImgReSampleContext * img_resample_full_i
     int srcSurface = (iwidth - rightBand - leftBand)* (iheight - topBand - bottomBand);
     // We use bilinear when the source surface is big, and bicubic when the number of pixels to handle is less than 1 MPixels
     s->context = sws_getContext(iwidth - rightBand - leftBand, 
-            iheight - topBand - bottomBand, PIX_FMT_YUV420P, owidth, oheight, 
-            PIX_FMT_YUV420P, srcSurface > 1024000 ? SWS_FAST_BILINEAR : SWS_BICUBIC, 
+            iheight - topBand - bottomBand, AV_PIX_FMT_YUV420P, owidth, oheight, 
+            AV_PIX_FMT_YUV420P, srcSurface > 1024000 ? SWS_FAST_BILINEAR : SWS_BICUBIC, 
             NULL, NULL, NULL);
     if (s->context == NULL) {
         av_free(s);

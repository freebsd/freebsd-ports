--- otherlibs/highgui/cvcap_ffmpeg.cpp.orgi	2008-04-28 20:29:51.000000000 +0200
+++ otherlibs/highgui/cvcap_ffmpeg.cpp	2008-04-28 20:32:58.000000000 +0200
@@ -41,9 +41,14 @@
 
 #include "_highgui.h"
 
+#define __STDC_CONSTANT_MACROS
 
 extern "C" {
 #include <ffmpeg/avformat.h>
+#include <ffmpeg/avcodec.h>
+#include <ffmpeg/swscale.h>
+#include <sys/types.h> /* size_t */
+#include <sys/errno.h>
 }
 
 #ifdef NDEBUG
@@ -52,6 +57,8 @@
 #define CV_WARN(message) fprintf(stderr, "warning: %s (%s:%d)\n", message, __FILE__, __LINE__)
 #endif
 
+static struct SwsContext *img_convert_ctx;
+
 typedef struct CvCaptureAVI_FFMPEG
 {
     CvCaptureVTable   * vtable;
@@ -214,19 +221,21 @@
 {
     if( !capture || !capture->video_st || !capture->picture->data[0] )
     return 0;
-#if LIBAVFORMAT_BUILD > 4628
-    img_convert( (AVPicture*)&capture->rgb_picture, PIX_FMT_BGR24,
-                 (AVPicture*)capture->picture,
-                 capture->video_st->codec->pix_fmt,
-                 capture->video_st->codec->width,
-                 capture->video_st->codec->height );
-#else
-    img_convert( (AVPicture*)&capture->rgb_picture, PIX_FMT_BGR24,
-                 (AVPicture*)capture->picture,
-                 capture->video_st->codec.pix_fmt,
-                 capture->video_st->codec.width,
-                 capture->video_st->codec.height );
-#endif
+
+    img_convert_ctx = sws_getContext(capture->video_st->codec->width,
+				     capture->video_st->codec->height,
+				     capture->video_st->codec->pix_fmt,
+				     capture->video_st->codec->width,
+				     capture->video_st->codec->height,
+				     PIX_FMT_BGR24,
+				     SWS_BICUBIC,
+				     NULL, NULL, NULL);
+    
+    sws_scale(img_convert_ctx, capture->picture->data, 
+	      capture->picture->linesize, 0,
+	      capture->video_st->codec->height, 
+	      capture->rgb_picture.data, capture->rgb_picture.linesize);
+    
     return &capture->frame;
 }
 
@@ -713,9 +722,20 @@
 				PIX_FMT_BGR24, image->width, image->height);
 
 		// convert to the color format needed by the codec
-		if( img_convert((AVPicture *)mywriter->picture, c->pix_fmt,
-					(AVPicture *)mywriter->rgb_picture, PIX_FMT_BGR24, 
-					image->width, image->height) < 0){
+		img_convert_ctx = sws_getContext(image->width,
+						 image->height,
+						 PIX_FMT_BGR24,
+						 c->width,
+						 c->height,
+						 c->pix_fmt,
+						 SWS_BICUBIC,
+						 NULL, NULL, NULL);
+		
+		if ( sws_scale(img_convert_ctx, mywriter->rgb_picture->data, 
+			       mywriter->rgb_picture->linesize, 0,
+			       image->height, 
+			       mywriter->picture->data, mywriter->picture->linesize) < 0 )
+		{
 			CV_ERROR(CV_StsUnsupportedFormat, "FFMPEG::img_convert pixel format conversion from BGR24 not handled");
 		}
 	}

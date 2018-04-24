https://github.com/opencv/opencv/commit/99091a62463e

--- modules/highgui/src/cap_ffmpeg_impl.hpp.orig	2016-09-16 15:55:58 UTC
+++ modules/highgui/src/cap_ffmpeg_impl.hpp
@@ -170,6 +170,10 @@ extern "C" {
 #define AV_PIX_FMT_GRAY16BE PIX_FMT_GRAY16BE
 #endif
 
+#ifndef PKT_FLAG_KEY
+#define PKT_FLAG_KEY AV_PKT_FLAG_KEY
+#endif
+
 #if LIBAVUTIL_BUILD >= (LIBAVUTIL_VERSION_MICRO >= 100 \
     ? CALC_FFMPEG_VERSION(52, 38, 100) : CALC_FFMPEG_VERSION(52, 13, 0))
 #define USE_AV_FRAME_GET_BUFFER 1
@@ -1478,7 +1482,11 @@ static AVStream *icv_add_video_stream_FFMPEG(AVFormatC
     // some formats want stream headers to be seperate
     if(oc->oformat->flags & AVFMT_GLOBALHEADER)
     {
+#if LIBAVCODEC_BUILD > CALC_FFMPEG_VERSION(56, 35, 0)
+        c->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
+#else
         c->flags |= CODEC_FLAG_GLOBAL_HEADER;
+#endif
     }
 #endif
 
@@ -1502,23 +1510,24 @@ static int icv_av_write_frame_FFMPEG( AVFormatContext 
 #endif
     int ret = OPENCV_NO_FRAMES_WRITTEN_CODE;
 
-    if (oc->oformat->flags & AVFMT_RAWPICTURE) {
+#if LIBAVFORMAT_BUILD < CALC_FFMPEG_VERSION(57, 0, 0)
+    if (oc->oformat->flags & AVFMT_RAWPICTURE)
+    {
         /* raw video case. The API will change slightly in the near
            futur for that */
         AVPacket pkt;
         av_init_packet(&pkt);
 
-#ifndef PKT_FLAG_KEY
-#define PKT_FLAG_KEY AV_PKT_FLAG_KEY
-#endif
-
         pkt.flags |= PKT_FLAG_KEY;
         pkt.stream_index= video_st->index;
         pkt.data= (uint8_t *)picture;
         pkt.size= sizeof(AVPicture);
 
         ret = av_write_frame(oc, &pkt);
-    } else {
+    }
+    else
+#endif
+    {
         /* encode the image */
         AVPacket pkt;
         av_init_packet(&pkt);
@@ -1676,7 +1685,9 @@ void CvVideoWriter_FFMPEG::close()
     /* write the trailer, if any */
     if(ok && oc)
     {
-        if( (oc->oformat->flags & AVFMT_RAWPICTURE) == 0 )
+#if LIBAVFORMAT_BUILD < CALC_FFMPEG_VERSION(57, 0, 0)
+        if (!(oc->oformat->flags & AVFMT_RAWPICTURE))
+#endif
         {
             for(;;)
             {
@@ -1910,7 +1921,10 @@ bool CvVideoWriter_FFMPEG::open( const char * filename
 
     outbuf = NULL;
 
-    if (!(oc->oformat->flags & AVFMT_RAWPICTURE)) {
+#if LIBAVFORMAT_BUILD < CALC_FFMPEG_VERSION(57, 0, 0)
+    if (!(oc->oformat->flags & AVFMT_RAWPICTURE))
+#endif
+    {
         /* allocate output buffer */
         /* assume we will never get codec output with more than 4 bytes per pixel... */
         outbuf_size = width*height*4;
@@ -2204,7 +2218,11 @@ AVStream* OutputMediaStream_FFMPEG::addVideoStream(AVF
         // some formats want stream headers to be seperate
         if (oc->oformat->flags & AVFMT_GLOBALHEADER)
         {
-            c->flags |= CODEC_FLAG_GLOBAL_HEADER;
+            #if LIBAVCODEC_BUILD > CALC_FFMPEG_VERSION(56, 35, 0)
+                c->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
+            #else
+                c->flags |= CODEC_FLAG_GLOBAL_HEADER;
+            #endif
         }
     #endif
 

--- lib/ogsf/gsd_img_mpeg.c.orig	2013-07-09 19:05:44 UTC
+++ lib/ogsf/gsd_img_mpeg.c
@@ -38,7 +38,7 @@
 #define STREAM_DURATION   5.0
 #define STREAM_FRAME_RATE 25	/* 25 images/s */
 #define STREAM_NB_FRAMES  ((int)(STREAM_DURATION * STREAM_FRAME_RATE))
-#define STREAM_PIX_FMT PIX_FMT_YUV420P	/* default pix_fmt */
+#define STREAM_PIX_FMT AV_PIX_FMT_YUV420P	/* default pix_fmt */
 
 AVFrame *picture, *tmp_picture;
 uint8_t *video_outbuf;
@@ -95,11 +95,11 @@ static AVStream *add_video_stream(AVForm
     c->time_base.num = 1;
     c->gop_size = 12;		/* emit one intra frame every twelve frames at most */
     c->pix_fmt = STREAM_PIX_FMT;
-    if (c->codec_id == CODEC_ID_MPEG2VIDEO) {
+    if (c->codec_id == AV_CODEC_ID_MPEG2VIDEO) {
 	/* just for testing, we also add B frames */
 	c->max_b_frames = 2;
     }
-    if (c->codec_id == CODEC_ID_MPEG1VIDEO) {
+    if (c->codec_id == AV_CODEC_ID_MPEG1VIDEO) {
 	/* Needed to avoid using macroblocks in which some coeffs overflow.
 	   This does not happen with normal video, it just happens here as
 	   the motion of the chroma plane does not match the luma plane. */
@@ -138,7 +138,7 @@ static AVFrame *alloc_picture(int pix_fm
     uint8_t *picture_buf;
     int size;
 
-    picture = avcodec_alloc_frame();
+    picture = av_frame_alloc();
 
     if (!picture)
 	return NULL;
@@ -210,8 +210,8 @@ static void open_video(AVFormatContext *
        picture is needed too. It is then converted to the required
        output format */
     tmp_picture = NULL;
-    if (c->pix_fmt != PIX_FMT_YUV420P) {
-	tmp_picture = alloc_picture(PIX_FMT_YUV420P, c->width, c->height);
+    if (c->pix_fmt != AV_PIX_FMT_YUV420P) {
+	tmp_picture = alloc_picture(AV_PIX_FMT_YUV420P, c->width, c->height);
 	if (!tmp_picture) {
 	    G_warning(_("Unable to allocate temporary picture"));
 	    return;
@@ -227,7 +227,7 @@ static void open_video(AVFormatContext *
  */
 static void write_video_frame(AVFormatContext * oc, AVStream * st)
 {
-    int out_size, ret;
+    int ret;
     AVCodecContext *c;
 
     c = st->codec;
@@ -250,15 +250,17 @@ static void write_video_frame(AVFormatCo
 	ret = av_write_frame(oc, &pkt);
     }
     else {
-	/* encode the image */
-	out_size =
-	    avcodec_encode_video(c, video_outbuf, video_outbuf_size, picture);
-	/* if zero size, it means the image was buffered */
-	if (out_size > 0) {
-	    AVPacket pkt;
+	AVPacket pkt;
+	int got_packet = 0;
 
-	    av_init_packet(&pkt);
+	av_init_packet(&pkt);
+	pkt.data = video_outbuf;
+	pkt.size = video_outbuf_size;
 
+	/* encode the image */
+	ret = avcodec_encode_video2(c, &pkt, picture, &got_packet);
+	/* if zero size, it means the image was buffered */
+	if (ret == 0 && got_packet && pkt.size > 0) {
 	    pkt.pts =
 		av_rescale_q(c->coded_frame->pts, c->time_base,
 			     st->time_base);
@@ -269,8 +271,6 @@ static void write_video_frame(AVFormatCo
 		pkt.flags |= AV_PKT_FLAG_KEY;
 #endif
 	    pkt.stream_index = st->index;
-	    pkt.data = video_outbuf;
-	    pkt.size = out_size;
 
 	    /* write the compressed frame in the media file */
 	    ret = av_write_frame(oc, &pkt);
@@ -362,11 +362,11 @@ int gsd_init_mpeg(const char *filename)
     /* if you want to hardcode the codec (eg #ifdef USE_XVID)
        this may be the place to do it (?????) */
 #ifdef USE_XVID
-    fmt->video_codec = CODEC_ID_XVID;
+    fmt->video_codec = AV_CODEC_ID_XVID;
 #endif
 
     video_st = NULL;
-    if (fmt->video_codec != CODEC_ID_NONE) {
+    if (fmt->video_codec != AV_CODEC_ID_NONE) {
 	video_st =
 	    add_video_stream(oc, fmt->video_codec, (r - l + 1), (t - b + 1));
     }

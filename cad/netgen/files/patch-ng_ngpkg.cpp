--- ng/ngpkg.cpp.orig	2014-08-29 09:54:01 UTC
+++ ng/ngpkg.cpp
@@ -2266,7 +2266,7 @@ namespace netgen
     static int gopsize = DEFAULT_GOP_SIZE;
     static int bframes = DEFAULT_B_FRAMES;
     static int MPGbufsize = DEFAULT_MPG_BUFSIZE;
-    static CodecID codec_id = CODEC_ID_MPEG1VIDEO;
+    static AVCodecID codec_id = AV_CODEC_ID_MPEG1VIDEO;
     static FILE *MPGfile;
     static buffer_t buff;
     static struct SwsContext *img_convert_ctx;
@@ -2338,7 +2338,7 @@ namespace netgen
         context->time_base = s;
         context->gop_size = gopsize;
         context->max_b_frames = bframes;
-        context->pix_fmt = PIX_FMT_YUV420P;
+        context->pix_fmt = AV_PIX_FMT_YUV420P;
         context->flags |= CODEC_FLAG_PSNR;
 
         // if( avcodec_open( context, codec ) < 0 ) {
@@ -2351,7 +2351,7 @@ namespace netgen
           return TCL_ERROR;
         }
 
-        YUVpicture = avcodec_alloc_frame();
+        YUVpicture = av_frame_alloc();
 
         YUVpicture->data[0] = buff.YUV;
         YUVpicture->data[1] = buff.YUV + PIXsize;
@@ -2360,7 +2360,7 @@ namespace netgen
         YUVpicture->linesize[1] = nx / 2;
         YUVpicture->linesize[2] = nx / 2;
 
-        RGBpicture = avcodec_alloc_frame();
+        RGBpicture = av_frame_alloc();
 
         RGBpicture->data[0] = buff.RGB;
         RGBpicture->data[1] = buff.RGB;
@@ -2405,8 +2405,8 @@ namespace netgen
         // Convert to YUV:
         //----------------
         if( img_convert_ctx == NULL )
-          img_convert_ctx = sws_getContext( nx, ny, PIX_FMT_RGB24,
-                                            nx, ny, PIX_FMT_YUV420P,
+          img_convert_ctx = sws_getContext( nx, ny, AV_PIX_FMT_RGB24,
+                                            nx, ny, AV_PIX_FMT_YUV420P,
                                             SWS_BICUBIC, NULL, NULL, NULL );
         
         if( img_convert_ctx == NULL ) {
@@ -2420,8 +2420,15 @@ namespace netgen
 
         // Encode frame:
         //--------------
-        bytes = avcodec_encode_video( context, buff.MPG,
-                                      MPGbufsize, YUVpicture );
+        AVPacket pkt;
+        av_init_packet( &pkt );
+        pkt.data = buff.MPG;
+        pkt.size = MPGbufsize;
+
+        int got_packet = 0;
+        int ret = avcodec_encode_video2( context, &pkt, YUVpicture,
+                                         &got_packet );
+        bytes = ret ? ret : pkt.size;
         count_frames++;
         print_info( count_frames, context, bytes );
         fwrite( buff.MPG, 1, bytes, MPGfile );
@@ -2442,8 +2449,15 @@ namespace netgen
 
         // Get the delayed frames, if any:
         //--------------------------------
+        AVPacket pkt;
+        av_init_packet( &pkt );
+        pkt.data = buff.MPG;
+        pkt.size = MPGbufsize;
+
+        int got_packet = 0;
         for( ; bytes; ) {
-          bytes = avcodec_encode_video( context, buff.MPG, MPGbufsize, NULL );
+          int ret = avcodec_encode_video2( context, &pkt, NULL, &got_packet );
+          bytes = ret ? ret : pkt.size;
           count_frames++;
           print_info( count_frames, context, bytes );
           fwrite( buff.MPG, 1, bytes, MPGfile );
@@ -2451,7 +2465,7 @@ namespace netgen
 
         // Add sequence end code:
         //-----------------------
-        if( codec_id == CODEC_ID_MPEG1VIDEO ) {
+        if( codec_id == AV_CODEC_ID_MPEG1VIDEO ) {
           buff.MPG[0] = 0x00;
           buff.MPG[1] = 0x00;
           buff.MPG[2] = 0x01;

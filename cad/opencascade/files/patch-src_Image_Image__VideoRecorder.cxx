src/Image/Image_VideoRecorder.cxx:279:25: error: use of undeclared identifier 'CODEC_FLAG_GLOBAL_HEADER'
    aCodecCtx->flags |= CODEC_FLAG_GLOBAL_HEADER;
                        ^
src/Image/Image_VideoRecorder.cxx:452:38: error: use of undeclared identifier 'AVFMT_RAWPICTURE'
  if ((myAVContext->oformat->flags & AVFMT_RAWPICTURE) != 0
                                     ^

--- src/Image/Image_VideoRecorder.cxx.orig	2018-05-25 19:13:49 UTC
+++ src/Image/Image_VideoRecorder.cxx
@@ -283,7 +283,7 @@ Standard_Boolean Image_VideoRecorder::ad
   // some formats want stream headers to be separate
   if (myAVContext->oformat->flags & AVFMT_GLOBALHEADER)
   {
-    aCodecCtx->flags |= CODEC_FLAG_GLOBAL_HEADER;
+    aCodecCtx->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
   }
   return Standard_True;
 #else
@@ -456,6 +456,7 @@ Standard_Boolean Image_VideoRecorder::wr
   AVPacket aPacket;
   memset (&aPacket, 0, sizeof(aPacket));
   av_init_packet (&aPacket);
+#ifdef AVFMT_RAWPICTURE
   if ((myAVContext->oformat->flags & AVFMT_RAWPICTURE) != 0
    && !theToFlush)
   {
@@ -468,6 +469,7 @@ Standard_Boolean Image_VideoRecorder::wr
     aResAv = av_interleaved_write_frame (myAVContext, &aPacket);
   }
   else
+#endif
   {
     // encode the image
     myFrame->pts = myFrameCount;

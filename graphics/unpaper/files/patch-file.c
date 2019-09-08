Subject: Fix wrong ffmpeg API usage
Origin: https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=800312
Bug: https://github.com/Flameeyes/unpaper/issues/39
Author: Andreas Cadhalpun <andreas.cadhalpun@googlemail.com>
Forwarded: https://github.com/Flameeyes/unpaper/pull/42

--- file.c.orig	2014-10-26 22:35:38 UTC
+++ file.c
@@ -93,10 +93,21 @@ void loadImage(const char *filename, AVFrame **image) 
     if (pkt.stream_index != 0)
         errOutput("unable to open file %s: invalid stream.", filename);
 
+    while (!got_frame && pkt.data) {
+
+        if (pkt.size <= 0) {
+            pkt.data = NULL;
+            pkt.size = 0;
+        }
+
     ret = avcodec_decode_video2(avctx, frame, &got_frame, &pkt);
     if (ret < 0) {
         av_strerror(ret, errbuff, sizeof(errbuff));
         errOutput("unable to open file %s: %s", filename, errbuff);
+    }
+
+        pkt.data += ret;
+        pkt.size -= ret;
     }
 
     switch(frame->format) {

--- ffmpeg-strip-wma/wmadec.c.orig	Thu Feb 26 12:26:00 2004
+++ ffmpeg-strip-wma/wmadec.c	Thu Feb 26 11:53:40 2004
@@ -1155,7 +1155,7 @@
         iptr = s->frame_out[ch];
 
         for(i=0;i<n;i++) {
-            a = lrintf(*iptr++);
+            a = rintf(*iptr++);
             if (a > 32767)
                 a = 32767;
             else if (a < -32768)

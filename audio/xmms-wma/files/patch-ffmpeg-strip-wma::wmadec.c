--- ffmpeg-strip-wma/wmadec.c	Mon Feb 23 03:46:59 2004
+++ ffmpeg-strip-wma/wmadec.c	Thu Mar 11 18:39:18 2004
@@ -1155,7 +1155,7 @@
         iptr = s->frame_out[ch];
 
         for(i=0;i<n;i++) {
-            a = lrintf(*iptr++);
+            a = rintf(*iptr++);
             if (a > 32767)
                 a = 32767;
             else if (a < -32768)

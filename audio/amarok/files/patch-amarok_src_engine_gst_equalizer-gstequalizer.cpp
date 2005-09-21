--- amarok/src/engine/gst/equalizer/gstequalizer.cpp.orig	Mon Sep 19 17:00:45 2005
+++ amarok/src/engine/gst/equalizer/gstequalizer.cpp	Mon Sep 19 17:00:58 2005
@@ -326,7 +326,7 @@
             out[channel] += pcm[channel]*0.25;
 
             /* Round and convert to integer */
-            tempgint = lrintf(out[channel]);
+            tempgint = (long int)rintf(out[channel]);
 
             /* Limit the output */
             if (tempgint < -32768)

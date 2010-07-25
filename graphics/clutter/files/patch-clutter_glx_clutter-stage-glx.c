--- clutter/glx/clutter-stage-glx.c.orig	2010-07-15 15:58:02.000000000 +0000
+++ clutter/glx/clutter-stage-glx.c	2010-07-15 15:58:25.000000000 +0000
@@ -487,8 +487,8 @@
                                     (retraceCount + 1) % 2,
                                     &retraceCount);
     }
-  else
 #ifdef __linux__
+  else
     {
       drm_wait_vblank_t blank;
 

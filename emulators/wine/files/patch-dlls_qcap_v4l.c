--- dlls/qcap/v4l.c.orig	2021-03-27 14:39:57 UTC
+++ dlls/qcap/v4l.c
@@ -63,9 +63,10 @@
 #include "qcap_main.h"
 #include "capture.h"
 
+WINE_DEFAULT_DEBUG_CHANNEL(qcap);
+
 #ifdef HAVE_LINUX_VIDEODEV2_H
 
-WINE_DEFAULT_DEBUG_CHANNEL(qcap);
 WINE_DECLARE_DEBUG_CHANNEL(winediag);
 
 static typeof(open) *video_open = open;

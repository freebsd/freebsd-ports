Author: Anatol Pomozov <anatol.pomozov@gmail.com>
http://git.alsa-project.org/?p=alsa-plugins.git;a=commitdiff;h=85ead33

--- a52/pcm_a52.c.orig	2015-10-27 13:34:06 UTC
+++ a52/pcm_a52.c
@@ -39,7 +39,7 @@
 #endif
 
 #if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(53, 34, 0)
-#include <libavutil/audioconvert.h>
+#include <libavutil/channel_layout.h>
 #include <libavutil/mem.h>
 #define USE_AVCODEC_FRAME
 #endif

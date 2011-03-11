--- src/ui_common.c.orig	2009-11-16 06:00:11.000000000 +0100
+++ src/ui_common.c	2011-02-08 16:21:18.283127798 +0100
@@ -46,7 +46,7 @@
 #include <medcon.h>
 #endif
 #ifdef AMIDE_FFMPEG_SUPPORT
-#include <ffmpeg/libavcodec/avcodec.h>
+#include <libavcodec/avcodec.h>
 #endif
 #ifdef AMIDE_LIBFAME_SUPPORT
 #include <fame_version.h>

--- src/player_ffmpeg.h.orig	2009-07-10 03:14:03.000000000 -0300
+++ src/player_ffmpeg.h	2013-10-08 19:36:06.326157022 -0300
@@ -23,13 +23,8 @@
 #include <QtCore>
 #include "player.h"
 extern "C" {
-#ifdef WIN32
 #include <libavcodec/avcodec.h>
 #include <libavformat/avformat.h>
-#else
-#include <avcodec.h>
-#include <avformat.h>
-#endif
 }
 
 class PlayThread : public QThread

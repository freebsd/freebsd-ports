--- src/osgPlugins/ffmpeg/FFmpegDecoderAudio.cpp.orig	2013-10-28 13:22:11.997950234 -0200
+++ src/osgPlugins/ffmpeg/FFmpegDecoderAudio.cpp	2013-10-28 13:22:39.838945189 -0200
@@ -9,6 +9,8 @@
 //#include <iostream>
 
 
+#define AVCODEC_MAX_AUDIO_FRAME_SIZE 192000 // 1 second of 48khz 32bit audio
+
 
 namespace osgFFmpeg {
 

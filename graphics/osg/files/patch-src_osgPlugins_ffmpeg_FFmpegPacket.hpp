--- src/osgPlugins/ffmpeg/FFmpegPacket.hpp.orig	2022-12-01 18:17:31 UTC
+++ src/osgPlugins/ffmpeg/FFmpegPacket.hpp
@@ -42,7 +42,7 @@ namespace osgFFmpeg
         void clear()
         {
             if (packet.data != 0)
-                av_free_packet(&packet);
+                av_packet_unref(&packet);
 
             release();
         }

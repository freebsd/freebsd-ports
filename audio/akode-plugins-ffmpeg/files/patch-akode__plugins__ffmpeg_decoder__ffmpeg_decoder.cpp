--- ./akode/plugins/ffmpeg_decoder/ffmpeg_decoder.cpp.orig	2006-08-10 15:37:20.000000000 -0300
+++ ./akode/plugins/ffmpeg_decoder/ffmpeg_decoder.cpp	2009-11-13 22:49:12.000000000 -0200
@@ -45,7 +45,7 @@
         aKode::File *file = (aKode::File*)opaque;
         return file->write((char*)buf, size);
     }
-    static offset_t akode_seek(void* opaque, offset_t pos, int whence)
+    static int64_t akode_seek(void* opaque, int64_t pos, int whence)
     {
         aKode::File *file = (aKode::File*)opaque;
         return file->seek(pos, whence);
@@ -314,7 +314,7 @@
     assert(d->packet.stream_index == d->audioStream);
 
 retry:
-    int len = avcodec_decode_audio( d->ic->streams[d->audioStream]->codec,
+    int len = avcodec_decode_audio2( d->ic->streams[d->audioStream]->codec,
                                     (short*)d->buffer, &d->buffer_size,
                                     d->packetData, d->packetSize );
 

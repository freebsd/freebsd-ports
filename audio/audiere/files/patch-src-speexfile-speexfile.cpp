--- src/speexfile/speexfile.cpp.orig	2006-02-14 07:57:01.000000000 +0300
+++ src/speexfile/speexfile.cpp	2008-06-16 04:56:31.000000000 +0400
@@ -871,7 +871,7 @@
 void *speexfile::header_to_decoder ( SpeexHeader *header, int enh_enabled, int *frame_size, int *rate, int *nframes, int forceMode, int *channels, SpeexStereoState *stereo )
 {
     void *st;
-    SpeexMode *mode;
+    const SpeexMode *mode;
     SpeexCallback callback;
     int modeID;
 

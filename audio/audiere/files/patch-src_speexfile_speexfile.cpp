--- src/speexfile/speexfile.cpp.orig	2006-02-14 04:57:01 UTC
+++ src/speexfile/speexfile.cpp
@@ -871,7 +871,7 @@ int speexfile::initfile ()
 void *speexfile::header_to_decoder ( SpeexHeader *header, int enh_enabled, int *frame_size, int *rate, int *nframes, int forceMode, int *channels, SpeexStereoState *stereo )
 {
     void *st;
-    SpeexMode *mode;
+    const SpeexMode *mode;
     SpeexCallback callback;
     int modeID;
 

--- app/client/Fingerprinter/LAV_Source.cpp.orig	2013-10-27 10:26:00.699715369 -0200
+++ app/client/Fingerprinter/LAV_Source.cpp	2013-10-27 10:26:26.826714410 -0200
@@ -44,6 +44,8 @@
 
 using namespace std;
 
+#define AVCODEC_MAX_AUDIO_FRAME_SIZE 192000
+
 
 /*
    Don't change these values!

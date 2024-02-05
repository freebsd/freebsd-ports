--- audio/drivers/alsa.cpp.orig	2022-01-29 16:19:41 UTC
+++ audio/drivers/alsa.cpp
@@ -616,6 +616,7 @@ AlsaAudio::~AlsaAudio()
       {
       stop();
       delete alsa;
+      delete midiDriver;
       }
 
 //---------------------------------------------------------

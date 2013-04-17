--- src/roundbeetle/NativeSDLSoundRenderer.cpp.orig	2013-04-12 09:21:38.324768572 +0200
+++ src/roundbeetle/NativeSDLSoundRenderer.cpp	2013-04-12 09:22:02.992763092 +0200
@@ -42,7 +42,7 @@
     desired.freq = _rendererFreqInHz;
     desired.format = AUDIO_S16;
     desired.channels = 2;
-    desired.samples = _rendererFreqInHz * bufferSizeInMS / 1000 * desired.channels;
+    desired.samples = 1024;
     desired.callback = fillerCallback;
     desired.userdata = this;
 }

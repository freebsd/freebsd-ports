--- sound.cpp.orig	Wed Mar 29 15:09:51 2006
+++ sound.cpp	Wed Mar 29 15:11:11 2006
@@ -288,6 +288,7 @@
 {
   int i;
   char filename[1000];
+  ALboolean loop;
 
   for (i=0; i<NUM_SOUNDS; i++) {
 #ifdef WINDOWS
@@ -296,8 +297,8 @@
     sprintf(filename, "%s/atr3d/sounds/%d.wav", DATADIR, i);
 #endif
 
-    alutLoadWAV(filename, &Wavs[i].wave, &Wavs[i].format,
-                &Wavs[i].size, &Wavs[i].bits, &Wavs[i].freq);
+    alutLoadWAVFile((ALbyte*)filename, &Wavs[i].format, &Wavs[i].wave,
+                &Wavs[i].size, &Wavs[i].freq, &loop);
   }
 }
 #endif

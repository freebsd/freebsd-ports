--- src/mixer.h.orig	2010-05-12 00:21:41.000000000 +0400
+++ src/mixer.h	2013-08-28 03:29:59.607226307 +0400
@@ -46,7 +46,7 @@
     bool audioHWInitialized;
 
 public:
-    Mixer(MixerMode mmode);
+    Mixer(MixerMode mmode = Realtime);
     ~Mixer();
     void Play();
     void Pause();

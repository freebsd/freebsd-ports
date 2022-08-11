- from Bug 265342 - audio/dexed: fix build on armv7 arm64 

--- Source/PluginProcessor.h.orig	2022-07-20 04:35:43 UTC
+++ Source/PluginProcessor.h
@@ -120,7 +120,7 @@ class DexedAudioProcessor  : public AudioProcessor, pu
     EngineOpl engineOpl;
     
     char clipboard[161];
-    char clipboardContent;
+    signed char clipboardContent;
     
     void resolvAppDir();
     

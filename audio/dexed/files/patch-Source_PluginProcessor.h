- from Bug 265342 - audio/dexed: fix build on armv7 arm64 

--- Source/PluginProcessor.h.orig	2024-07-14 16:47:34 UTC
+++ Source/PluginProcessor.h
@@ -129,7 +129,7 @@ class DexedAudioProcessor  : public AudioProcessor, pu
     EngineOpl engineOpl;
     
     char clipboard[161];
-    char clipboardContent;
+    signed char clipboardContent;
     
     void resolvAppDir();
     

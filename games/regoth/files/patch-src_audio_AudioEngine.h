--- src/audio/AudioEngine.h.orig	2020-01-06 00:37:37 UTC
+++ src/audio/AudioEngine.h
@@ -5,7 +5,7 @@
 
 #include <glm/glm.hpp>
 
-typedef struct ALCdevice_struct ALCdevice;
+typedef struct ALCdevice ALCdevice;
 
 namespace Audio
 {

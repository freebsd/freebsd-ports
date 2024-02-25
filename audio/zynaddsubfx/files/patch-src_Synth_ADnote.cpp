--- src/Synth/ADnote.cpp.orig	2022-01-22 01:46:21 UTC
+++ src/Synth/ADnote.cpp
@@ -1264,7 +1264,7 @@ inline void ADnote::ComputeVoiceOscillator_SincInterpo
 inline void ADnote::ComputeVoiceOscillator_SincInterpolation(int nvoice)
 {
     // windowed sinc kernel factor Fs*0.3, rejection 80dB
-    const float_t kernel[] = {
+    const float kernel[] = {
         0.0010596256917418426f,
         0.004273442181254887f,
         0.0035466063043375785f,

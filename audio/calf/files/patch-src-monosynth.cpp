--- src/monosynth.cpp.orig	2015-01-10 10:25:16 UTC
+++ src/monosynth.cpp
@@ -309,7 +309,7 @@ void monosynth_audio_module::calculate_b
     {
         float freq = fabs(*params[par_o2unisonfrq] / muls[7]);
         if (moddest[moddest_o2unisondetune] != 0)
-            freq *= pow(2.0, moddest[moddest_o2unisondetune]);
+            freq *= pow(2.0, (double)moddest[moddest_o2unisondetune]);
         unison_osc.set_freq(freq, srate);
         last_unison_scale = 1.0 / (1.0 + 2 * last_unison);
         unison_scale = 1.0 / (1.0 + 2 * unison);

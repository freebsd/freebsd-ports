--- src/modules_dist.cpp.orig	2015-03-13 23:00:12 UTC
+++ src/modules_dist.cpp
@@ -794,8 +794,8 @@ uint32_t tapesimulator_audio_module::pro
             lfo2.advance(1);
             
             // dot
-            rms = std::max((double)rms, (fabs(Lo) + fabs(Ro)) / 2);
-            input = std::max((double)input, (fabs(Lc) + fabs(Rc)) / 2);
+            rms = std::max(rms, (fabsf(Lo) + fabsf(Ro)) / 2);
+            input = std::max(input, (fabsf(Lc) + fabsf(Rc)) / 2);
             
             float values[] = {inL, inR, outs[0][i], outs[1][i]};
             meters.process(values);

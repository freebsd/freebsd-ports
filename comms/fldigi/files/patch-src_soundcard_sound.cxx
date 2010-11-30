--- src/soundcard/sound.cxx.orig	2010-11-27 08:29:59.000000000 -0500
+++ src/soundcard/sound.cxx	2010-11-27 08:36:45.000000000 -0500
@@ -364,7 +364,7 @@
 {
 	int sndparam;
 // Try to get ~100ms worth of samples per fragment
-	sndparam = (int)log2(sample_frequency * 0.1);
+	sndparam = (int)log(sample_frequency * 0.1)/log(2.0);
 // double since we are using 16 bit samples
 	sndparam += 1;
 // Unlimited amount of buffers for RX, four for TX

--- src/soundcard/sound.cxx.orig	2011-04-05 10:48:40.000000000 -0400
+++ src/soundcard/sound.cxx	2011-04-16 14:40:29.000000000 -0400
@@ -380,7 +380,7 @@
 {
 	int sndparam;
 // Try to get ~100ms worth of samples per fragment
-	sndparam = (int)log2(sample_frequency * 0.1);
+	sndparam = (int)log(sample_frequency * 0.1)/log(2.0);
 // double since we are using 16 bit samples
 	sndparam += 1;
 // Unlimited amount of buffers for RX, four for TX

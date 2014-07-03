--- quisk.c.orig	2014-06-28 19:10:12.000000000 -0700
+++ quisk.c	2014-06-28 19:10:48.000000000 -0700
@@ -1156,7 +1156,7 @@
 		if (filter_bandwidth < 19000) {		// No filtering for wide bandwidth
 			for (i = 0; i < nSamples; i++)
 				cSamples[i] = dRxFilterOut(cSamples[i], bank);
-			measure_audio_sum += cSamples[i] * conj(cSamples[i]);
+			measure_audio_sum = measure_audio_sum + cSamples[i] * conj(cSamples[i]);
 			measure_audio_count += 1;
 		}
 		break;

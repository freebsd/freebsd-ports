--- tools/bsefextract.cc.orig	2010-09-16 10:07:57.000000000 +0000
+++ tools/bsefextract.cc	2010-09-16 10:08:06.000000000 +0000
@@ -1120,7 +1120,7 @@
 	  fft_size_samples);
 	g_printerr ("  * stepping     %5.2f ms    %6u samples\n",
 	  float (options.timing_window_stepping_ms),
-	  uint (options.timing_window_stepping_ms * signal.mix_freq() / 1000));
+	  unsigned (options.timing_window_stepping_ms * signal.mix_freq() / 1000));
       }
 
     for (double offset_ms = 0; offset_ms < file_size_ms; offset_ms += options.timing_window_stepping_ms)

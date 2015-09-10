--- qsstv/drmrx/demodulator.cpp.orig	2014-12-06 14:41:00 UTC
+++ qsstv/drmrx/demodulator.cpp
@@ -941,7 +941,7 @@ bool demodulator::channelEstimation()
           temp2 += actual_pilots[2 * j] * next_pilots[2 * j + 1] -actual_pilots[2 * j + 1] * next_pilots[2 * j];
 
         }
-      if (i != 0)  delta_freq_offset = (float) atan2(temp2, temp1 + MIN_ABS_H);
+      if (i != 0)  delta_freq_offset = (float) atan2(temp2, (float)(temp1 + MIN_ABS_H));
 
       for (j = 0; j < K_max - K_min + 1; j++)
         {

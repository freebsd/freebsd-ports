--- buf.c.orig	2014-06-27 18:11:24.000000000 -0700
+++ buf.c	2014-06-27 18:11:33.000000000 -0700
@@ -1292,7 +1292,7 @@
 memset(fft1_char,0,fft1_bytes);
 memset(liminfo,0,2*fft1_size*sizeof(float));
 memset(liminfo_wait,0,fft1_size*sizeof(unsigned char));
-memset(fft1_slowsum,0.1,fft1_size*sizeof(float));
+memset(fft1_slowsum,0,fft1_size*sizeof(float));
 if(fft1_correlation_flag)memset(fft1_slowcorr,0,2*fft1_size*sizeof(float));
 memset(wg_waterf_sum,0,fft1_size*sizeof(float));
 memset(timf1_char,0,timf1_bytes);

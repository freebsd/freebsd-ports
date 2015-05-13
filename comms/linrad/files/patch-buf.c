--- buf.c.orig	2014-11-04 10:25:00 UTC
+++ buf.c
@@ -1328,7 +1328,7 @@ if( (ui.network_flag & NET_RXIN_FFT1) ==
 memset(fft1_char,0,fft1_bytes);
 memset(liminfo,0,2*fft1_size*sizeof(float));
 memset(liminfo_wait,0,fft1_size*sizeof(unsigned char));
-memset(fft1_slowsum,0.1,fft1_size*sizeof(float));
+memset(fft1_slowsum,0,fft1_size*sizeof(float));
 if(fft1_correlation_flag)memset(fft1_slowcorr,0,2*fft1_size*sizeof(float));
 memset(wg_waterf_sum,0,fft1_size*sizeof(float));
 memset(timf1_char,0,timf1_bytes);

--- buf.c.orig	2014-11-04 10:25:00 UTC
+++ buf.c
@@ -583,7 +583,7 @@ else
   }
 t1+=5;
 t1*=timf3_sampling_speed;
-if(t1*genparm[MIX1_NO_OF_CHANNELS]*2*twice_rxchan*sizeof(float) > 0x7fffffff)
+if((unsigned long)(t1*genparm[MIX1_NO_OF_CHANNELS]*2*twice_rxchan*sizeof(float)) > 0x7fffffffUL)
   {
   t1=0x7fffffff/(genparm[MIX1_NO_OF_CHANNELS]*2*twice_rxchan*sizeof(float));
   }
@@ -672,7 +672,7 @@ else
   fft1afc_flag=1;
   }  
 t1=max_fft1_sumsq*fft1_size*sizeof(float);
-if(t1 > 0x3ffffff)
+if((unsigned long)t1 > 0x3ffffffUL)
   {
   max_fft1_sumsq=0x3fffffff/(fft1_size*sizeof(float));
   } 
@@ -1328,7 +1328,7 @@ if( (ui.network_flag & NET_RXIN_FFT1) == 0)
 memset(fft1_char,0,fft1_bytes);
 memset(liminfo,0,2*fft1_size*sizeof(float));
 memset(liminfo_wait,0,fft1_size*sizeof(unsigned char));
-memset(fft1_slowsum,0.1,fft1_size*sizeof(float));
+memset(fft1_slowsum,0,fft1_size*sizeof(float));
 if(fft1_correlation_flag)memset(fft1_slowcorr,0,2*fft1_size*sizeof(float));
 memset(wg_waterf_sum,0,fft1_size*sizeof(float));
 memset(timf1_char,0,timf1_bytes);

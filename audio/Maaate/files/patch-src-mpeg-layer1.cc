--- src/mpeg/layer1.cc.orig	Thu Jan 10 00:32:43 2002
+++ src/mpeg/layer1.cc	Sat Jul 20 17:21:11 2002
@@ -235,25 +235,25 @@
 }
 
 float
-Layer1::scalefactor (unsigned int channel, unsigned int subband, unsigned int ss=0) 
+Layer1::scalefactor (unsigned int channel, unsigned int subband, unsigned int ss) 
 {
     return maaate_scalefactors[scale_index[channel][subband]];
 }
 
 int
-Layer1::sample (unsigned int channel, unsigned int subb, unsigned int number, unsigned int ss=0) 
+Layer1::sample (unsigned int channel, unsigned int subb, unsigned int number, unsigned int ss) 
 {
     return samples[number][channel][subb];
 }
 
 double
-Layer1::restored_sample (unsigned int ch, unsigned int subb, unsigned int no, unsigned int ss=0) 
+Layer1::restored_sample (unsigned int ch, unsigned int subb, unsigned int no, unsigned int ss) 
 {
     return restoredsamples[no][ch][subb];
 }
 
 short
-Layer1::pcm_sample (unsigned int ch, unsigned int subb, unsigned int no, unsigned int ss=0) 
+Layer1::pcm_sample (unsigned int ch, unsigned int subb, unsigned int no, unsigned int ss) 
 {
     return pcm[no][ch][subb];
 }

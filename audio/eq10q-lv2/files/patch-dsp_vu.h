--- dsp/vu.h.orig	2016-12-11 12:07:54 UTC
+++ dsp/vu.h
@@ -49,7 +49,7 @@ static inline void resetVU(Vu *vu)
 //Inputs a sample to VU
 static inline void SetSample(Vu *vu, float sample)
 {
-  vu->vu_value = fabsf(sample);
+  vu->vu_value = fabs(sample);
   vu->vu_max = vu->vu_value > vu->vu_max ? vu->vu_value :  vu->vu_max;
 }
 

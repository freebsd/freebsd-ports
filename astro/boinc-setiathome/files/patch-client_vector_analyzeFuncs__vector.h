--- client/vector/analyzeFuncs_vector.h.orig	2018-12-18 12:22:10 UTC
+++ client/vector/analyzeFuncs_vector.h
@@ -275,7 +275,7 @@ extern int v_vGetPowerSpectrumUnrolled2(  
                               );
 #endif
 
-#ifdef USE_ALTIVEC
+#if defined(USE_ALTIVEC) && defined(__APPLE)
 extern int v_vGetPowerSpectrumG4(
                                 sah_complex * cx_FreqData,
                                 float * fp_PowerSpectrum,

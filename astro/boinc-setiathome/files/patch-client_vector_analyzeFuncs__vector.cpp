--- client/vector/analyzeFuncs_vector.cpp.orig	2018-01-14 23:02:12 UTC
+++ client/vector/analyzeFuncs_vector.cpp
@@ -101,7 +101,7 @@
 #if defined(HAVE__ISNAN)
 #define isnotnan(x) (!_isnan(x))
 #elif defined(HAVE_ISNAN)
-#define isnotnan(x) (!isnan(x))
+#define isnotnan(x) (!std::isnan(x))
 #elif defined(HAVE___ISNAN)
 #define isnotnan(x) (!__isnan(x))
 #else
@@ -338,7 +338,7 @@ bool found_baseline_smooth=false;
 
 GPStb GetPowerSpectrumFuncs[]={
     v_GetPowerSpectrum, BA_ANY, "v_GetPowerSpectrum",
-#ifdef USE_ALTIVEC
+#if defined(USE_ALTIVEC) && defined(__APPLE__)
     v_vGetPowerSpectrum, BA_ALTVC, "v_vGetPowerSpectrum", 
     v_vGetPowerSpectrumG4, BA_ALTVC,"v_vGetPowerSpectrumG4",
 #endif
@@ -374,7 +374,7 @@ CDtb ChirpDataFuncs[]={
     fpu_ChirpData, BA_ANY, "fpu_ChirpData",
     fpu_opt_ChirpData, BA_ANY, "fpu_opt_ChirpData",
 #endif
-#ifdef USE_ALTIVEC
+#if defined(USE_ALTIVEC) && defined(__APPLE__)
     v_vChirpData, BA_ALTVC, "v_vChirpData",  
     v_vChirpDataG4, BA_ALTVC, "v_vChirpDataG4",
     v_vChirpDataG5, BA_ALTVC, "v_vChirpDataG5",
@@ -432,7 +432,7 @@ TPtb TransposeFuncs[]={
 #ifdef USE_FFTWF
     fftwf_transpose, BA_ANY, "fftwf_transpose",
 #endif
-#ifdef USE_ALTIVEC
+#if defined(USE_ALTIVEC) && defined(__APPLE__)
     v_vTranspose, BA_ALTVC, "v_vTranspose",
 #endif
 #ifdef USE_SSE 
@@ -461,7 +461,7 @@ TPtb TransposeFuncs[]={
      v_avxTranspose8x8ntw_b, BA_AVX, "v_avxTranspose8x8ntw_b", 
 #  endif
 #endif
-#if (defined(__arm__) && defined(__VFP_FP__) && !defined(__SOFTFP__)) || defined(__arch64__)
+#if (defined(__arm__) && defined(__VFP_FP__) && !defined(__SOFTFP__)) || defined(__aarch64__)
     v_pfTranspose2, BA_VFP, "v_pfTranspose2",      
     v_pfTranspose4, BA_VFP, "v_pfTranspose4",      
     v_pfTranspose8, BA_VFP, "v_pfTranspose8",      
@@ -476,7 +476,7 @@ bool found_transpose=false;
 
 FolSub FoldSubs[] = {
   &swifold,      BA_ANY,
-#ifdef USE_ALTIVEC
+#if defined(USE_ALTIVEC) && defined(__APPLE__)
   &AKavfold,     BA_ALTVC,
 #endif
 #ifdef USE_SSE 

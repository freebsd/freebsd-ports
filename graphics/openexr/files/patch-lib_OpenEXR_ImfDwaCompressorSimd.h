--- ./src/lib/OpenEXR/ImfDwaCompressorSimd.h.orig	2023-03-05 20:23:47 UTC
+++ ./src/lib/OpenEXR/ImfDwaCompressorSimd.h
@@ -395,7 +395,7 @@ convertFloatToHalf64_scalar (unsigned short* dst, floa
         dst[i] = ((half) src[i]).bits ();
 }
 
-#ifdef IMF_HAVE_NEON
+#ifdef IMF_HAVE_NEON_AARCH64
 
 void
 convertFloatToHalf64_neon (unsigned short* dst, float* src)
@@ -821,7 +821,7 @@ fromHalfZigZag_f16c (unsigned short* src, float* dst)
 #endif /* defined IMF_HAVE_GCC_INLINEASM_X86_64 */
 }
 
-#ifdef IMF_HAVE_NEON
+#ifdef IMF_HAVE_NEON_AARCH64
 
 
 void
@@ -856,7 +856,7 @@ fromHalfZigZag_neon(unsigned short* __restrict__ src, 
     }
 }
 
-#endif // IMF_HAVE_NEON
+#endif // IMF_HAVE_NEON_AARCH64
 
 //
 // Inverse 8x8 DCT, only inverting the DC. This assumes that

--- src/sound/SwiftResampler_altivec.inc.orig	2024-05-08 15:12:59 UTC
+++ src/sound/SwiftResampler_altivec.inc
@@ -1,3 +1,4 @@
+#include <altivec.h>
 template<unsigned TA_NumFractBits>
 static INLINE void DoMAC_AltiVec(const int16 *wave, const int16 *coeffs, int32 count, int32 *accum_output)
 {

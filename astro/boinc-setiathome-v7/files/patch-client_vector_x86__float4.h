--- client/vector/x86_float4.h.orig	2011-05-22 19:08:50 UTC
+++ client/vector/x86_float4.h
@@ -58,11 +58,15 @@ extern const_float4 INDGEN[2];
 
 ALIGNED(static const int sign_bits[4],16)={INT_MIN, INT_MIN, INT_MIN, INT_MIN};
 ALIGNED(static const int other_bits[4],16)={INT_MAX, INT_MAX, INT_MAX, INT_MAX};
+
+#ifdef __clang__
+#ifndef __EMMINTRIN_H
+typedef long long __m128i __attribute__((__vector_size__(16)));
+#endif
+#endif
 #define SIGN_BITS (*(__m128i *)sign_bits)
 #define OTHER_BITS (*(__m128i *)other_bits)
 
-
-
 struct float4 {
        float4() {};
        float4(const __m128 b) { m=b; };
@@ -263,4 +267,3 @@ struct const_float4 : public float4 {
 
 #endif
 #endif
-

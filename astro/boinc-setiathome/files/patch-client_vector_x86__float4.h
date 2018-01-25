--- client/vector/x86_float4.h.orig	2018-01-14 23:02:12 UTC
+++ client/vector/x86_float4.h
@@ -58,8 +58,8 @@ extern const_float4 INDGEN[2];
 
 ALIGNED(static const int sign_bits[4],16)={INT_MIN, INT_MIN, INT_MIN, INT_MIN};
 ALIGNED(static const int other_bits[4],16)={INT_MAX, INT_MAX, INT_MAX, INT_MAX};
-#define SIGN_BITS (*(__m128i *)sign_bits)
-#define OTHER_BITS (*(__m128i *)other_bits)
+#define SIGN_BITS (*(__m128 *)sign_bits)
+#define OTHER_BITS (*(__m128 *)other_bits)
 
 
 
@@ -104,19 +104,19 @@ struct float4 {
 #endif
 	      return  rv;
        };
-       inline float4 operator |(const __m128i &b) const {
+       inline float4 operator |(const __m128 &b) const {
               register float4 rv;
 #ifdef USE_INTRINSICS
-	          rv.m=_mm_or_ps(*(__m128 *)&b,m);
+	          rv.m=_mm_or_ps(b,m);
 #elif defined(__GNUC__)
               __asm__ ( "orps %2,%0" : "=x" (rv.m) : "0" (b), "xm" (m));
 #endif
 	      return rv;
        };
-       inline float4 operator &(const __m128i &b) const {
+       inline float4 operator &(const __m128 &b) const {
               register float4 rv;
 #ifdef USE_INTRINSICS
-	      rv.m=_mm_and_ps(*(__m128 *)&b,m);
+	      rv.m=_mm_and_ps(b,m);
 #elif defined(__GNUC__)
               __asm__ ( "andps %2,%0" : "=x" (rv.m) : "0" (b), "xm" (m));
 #endif
@@ -159,7 +159,9 @@ struct float4 {
 	      return *this;
        }
        inline operator __m128() {return m;};
+#ifdef __SSE2__
        inline operator __m128i() {return *(__m128i *)&m; };
+#endif
        inline float4 abs() const {
               // clear the sign bits
               return *this & OTHER_BITS;
@@ -258,7 +260,9 @@ struct const_float4 : public float4 {
     inline const_float4(const float4 &b) { m=b.m; };
     inline operator float4() const { return *this; };
     inline operator __m128() {return m;};
+#ifdef __SSE2__
     inline operator __m128i() {return *(__m128i *)&m; };
+#endif
 };
 
 #endif

--- client/vector/analyzeFuncs_sse.cpp.orig	2013-06-26 16:56:49 UTC
+++ client/vector/analyzeFuncs_sse.cpp
@@ -191,7 +191,7 @@ inline void v_vsubTranspose4(float *in, 
     prefetcht0(out+3*yline);
     // TODO: figure out why the intrinsic version crashes for MinGW build
     // not critical, but shuffle-only _MM_TRANSPOSE4_PS is optimal on some
-#if defined(USE_INTRINSICS) && defined(_MM_TRANSPOSE4_PS) && !defined(__GNUC__)
+#if defined(USE_INTRINSICS) && (defined(_MM_TRANSPOSE4_PS) && !defined(__GNUC__) || defined(__clang__))
     register float4 row0=*(__m128 *)in;
     register float4 row1=*(__m128 *)(in+xline);
     register float4 row2=*(__m128 *)(in+2*xline);
@@ -273,7 +273,7 @@ inline void v_vsubTranspose4np(float *in
 
     // TODO: figure out why the intrinsic version crashes for MinGW build
     // not critical, but the shuffle-only _MM_TRANSPOSE4_PS is optimal on some
-#if defined(USE_INTRINSICS) && defined(_MM_TRANSPOSE4_PS) && !defined(__GNUC__)
+#if defined(USE_INTRINSICS) && (defined(_MM_TRANSPOSE4_PS) && !defined(__GNUC__) || defined(__clang__))
     register float4 row0=*(__m128 *)in;
     register float4 row1=*(__m128 *)(in+xline);
     register float4 row2=*(__m128 *)(in+2*xline);
@@ -1592,8 +1592,14 @@ inline float s_maxp2f( __m128 max1 ) {
     return ( tMax );
 }
 
+#ifdef __clang__
+#define s_getU( aaaa, ptr )  \
+	aaaa = _mm_loadl_pi(aaaa, (__m64 *)ptr); \
+	aaaa = _mm_loadh_pi(aaaa, ((__m64 *)(ptr))+1 )
+#else
 #define s_getU( aaaa, ptr )  \
         aaaa = _mm_loadh_pi( _mm_loadl_pi(aaaa, (__m64 *)ptr), ((__m64 *)(ptr))+1 )
+#endif
 
 #define s_putU( ptr, aaaa ) \
         _mm_storel_pi((__m64 *)ptr, aaaa), _mm_storeh_pi( ((__m64 *)ptr)+1 , aaaa)

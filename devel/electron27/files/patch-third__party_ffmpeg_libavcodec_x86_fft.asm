--- third_party/ffmpeg/libavcodec/x86/fft.asm.orig	2023-08-10 01:51:13 UTC
+++ third_party/ffmpeg/libavcodec/x86/fft.asm
@@ -296,6 +296,7 @@ INIT_YMM avx
 %if HAVE_AVX_EXTERNAL
 align 16
 fft8_avx:
+    _CET_ENDBR
     mova      m0, Z(0)
     mova      m1, Z(1)
     T8_AVX    m0, m1, m2, m3, m4
@@ -306,6 +307,7 @@ fft8_avx:
 
 align 16
 fft16_avx:
+    _CET_ENDBR
     mova       m2, Z(2)
     mova       m3, Z(3)
     T4_SSE     m2, m3, m7
@@ -343,6 +345,7 @@ fft16_avx:
 
 align 16
 fft32_avx:
+    _CET_ENDBR
     call fft16_avx
 
     mova m0, Z(4)
@@ -367,6 +370,7 @@ fft32_avx:
     ret
 
 fft32_interleave_avx:
+    _CET_ENDBR
     call fft32_avx
     mov r2d, 32
 .deint_loop:
@@ -390,6 +394,7 @@ INIT_XMM sse
 align 16
 fft4_avx:
 fft4_sse:
+    _CET_ENDBR
     mova     m0, Z(0)
     mova     m1, Z(1)
     T4_SSE   m0, m1, m2
@@ -399,6 +404,7 @@ fft4_sse:
 
 align 16
 fft8_sse:
+    _CET_ENDBR
     mova     m0, Z(0)
     mova     m1, Z(1)
     T4_SSE   m0, m1, m2
@@ -413,6 +419,7 @@ fft8_sse:
 
 align 16
 fft16_sse:
+    _CET_ENDBR
     mova     m0, Z(0)
     mova     m1, Z(1)
     T4_SSE   m0, m1, m2
@@ -441,6 +448,7 @@ fft16_sse:
 %macro DECL_PASS 2+ ; name, payload
 align 16
 %1:
+    _CET_ENDBR
 DEFINE_ARGS zc, w, n, o1, o3
     lea o3q, [nq*3]
     lea o1q, [nq*8]
@@ -457,10 +465,6 @@ DEFINE_ARGS zc, w, n, o1, o3
 %macro FFT_DISPATCH 2; clobbers 5 GPRs, 8 XMMs
     lea r2, [dispatch_tab%1]
     mov r2, [r2 + (%2q-2)*gprsize]
-%ifdef PIC
-    lea r3, [$$]
-    add r2, r3
-%endif
     call r2
 %endmacro ; FFT_DISPATCH
 
@@ -585,11 +589,7 @@ cglobal imdct_calc, 3,5,3
     jl      .loop
     RET
 
-%ifdef PIC
-%define SECTION_REL - $$
-%else
 %define SECTION_REL
-%endif
 
 %macro DECL_FFT 1-2 ; nbits, suffix
 %ifidn %0, 1
@@ -613,6 +613,7 @@ cglobal imdct_calc, 3,5,3
 
 align 16
 fft %+ n %+ fullsuffix:
+    _CET_ENDBR
     call fft %+ n2 %+ SUFFIX
     add r0, n*4 - (n&(-2<<%1))
     call fft %+ n4 %+ SUFFIX
@@ -627,8 +628,10 @@ fft %+ n %+ fullsuffix:
 %endrep
 %undef n
 
+[SECTION .data.rel.ro write]
 align 8
 dispatch_tab %+ fullsuffix: pointer list_of_fft
+__?SECT?__
 %endmacro ; DECL_FFT
 
 %if HAVE_AVX_EXTERNAL

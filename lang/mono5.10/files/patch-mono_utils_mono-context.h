--- mono/utils/mono-context.h.orig	2018-04-13 23:37:57 UTC
+++ mono/utils/mono-context.h
@@ -24,23 +24,30 @@
 
 #if defined(TARGET_X86)
 #if defined(__APPLE__)
+#define MONO_HAVE_SIMD_REG
 typedef struct __darwin_xmm_reg MonoContextSimdReg;
 #endif
 #elif defined(TARGET_AMD64)
 #if defined(__APPLE__)
+#define MONO_HAVE_SIMD_REG
 typedef struct __darwin_xmm_reg MonoContextSimdReg;
 #elif defined(__linux__) && defined(__GLIBC__)
+#define MONO_HAVE_SIMD_REG
 typedef struct _libc_xmmreg MonoContextSimdReg;
 #elif defined(HOST_WIN32)
+#define MONO_HAVE_SIMD_REG
 #include <emmintrin.h>
 typedef __m128d MonoContextSimdReg;
 #elif defined(HOST_ANDROID)
+#define MONO_HAVE_SIMD_REG
 typedef struct _libc_xmmreg MonoContextSimdReg;
 #elif defined(__linux__)
+#define MONO_HAVE_SIMD_REG
 #include <emmintrin.h>
 typedef __m128d MonoContextSimdReg;
 #endif
 #elif defined(TARGET_ARM64)
+#define MONO_HAVE_SIMD_REG
 typedef __uint128_t MonoContextSimdReg;
 #endif
 
@@ -255,7 +262,7 @@ typedef struct {
 
 typedef struct {
 	mgreg_t gregs [AMD64_NREG];
-#if defined(__APPLE__) || (defined(__linux__) && defined(__GLIBC__)) || defined(HOST_WIN32)
+#if defined(MONO_HAVE_SIMD_REG)
 	MonoContextSimdReg fregs [AMD64_XMM_NREG];
 #else
 	double fregs [AMD64_XMM_NREG];

--- libs/JUCE/modules/juce_dsp/juce_dsp.h.orig	2026-06-05 07:45:45 UTC
+++ libs/JUCE/modules/juce_dsp/juce_dsp.h
@@ -84,6 +84,17 @@
 
  #include <arm_neon.h>
 
+#elif defined (__powerpc__)
+
+ #ifndef JUCE_USE_SIMD
+  #define JUCE_USE_SIMD 1
+ #endif
+
+ #ifndef SIMDE_ENABLE_NATIVE_ALIASES
+  #define SIMDE_ENABLE_NATIVE_ALIASES
+ #endif
+ #include <simde/x86/sse4.2.h>
+
 #else
 
  // No SIMD Support
@@ -225,7 +236,7 @@ namespace util
  #include "native/juce_SIMDNativeOps_fallback.h"
 
  // include the correct native file for this build target CPU
- #if defined(__i386__) || defined(__amd64__) || defined(_M_X64) || defined(_X86_) || defined(_M_IX86) || defined(__riscv) || defined(__EMSCRIPTEN__)
+ #if defined(__i386__) || defined(__amd64__) || defined(_M_X64) || defined(_X86_) || defined(_M_IX86) || defined(__riscv) || defined(__EMSCRIPTEN__) || defined(__powerpc__)
   #ifdef __AVX2__
    #include "native/juce_SIMDNativeOps_avx.h"
   #else

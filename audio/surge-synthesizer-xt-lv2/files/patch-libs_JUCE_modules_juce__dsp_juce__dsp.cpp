--- libs/JUCE/modules/juce_dsp/juce_dsp.cpp.orig	2026-06-05 07:46:02 UTC
+++ libs/JUCE/modules/juce_dsp/juce_dsp.cpp
@@ -79,7 +79,7 @@
 #include "widgets/juce_Chorus.cpp"
 
 #if JUCE_USE_SIMD
- #if JUCE_INTEL || defined(__riscv) || defined(__EMSCRIPTEN__)
+ #if JUCE_INTEL || defined(__riscv) || defined(__EMSCRIPTEN__) || defined(__powerpc__)
  // falkTX patch to 6.* was this so ... add those ORs above
  // #if defined(__i386__) || defined(__amd64__) || defined(_M_X64) || defined(_X86_) || defined(_M_IX86) || defined(__riscv) || defined(__EMSCRIPTEN__)
   #ifdef __AVX2__

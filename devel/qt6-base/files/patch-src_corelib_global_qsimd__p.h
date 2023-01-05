--- src/corelib/global/qsimd_p.h.orig	2023-01-05 22:52:06 UTC
+++ src/corelib/global/qsimd_p.h
@@ -212,15 +212,6 @@ asm(
 //
 // macOS's fat binaries support the "x86_64h" sub-architecture and the GNU libc
 // ELF loader also supports a "haswell/" subdir (e.g., /usr/lib/haswell).
-#  define ARCH_HASWELL_MACROS       (__AVX2__ + __BMI2__ + __FMA__ + __LZCNT__)
-#  if ARCH_HASWELL_MACROS != 0
-#    if ARCH_HASWELL_MACROS != 4
-#      error "Please enable all x86-64-v3 extensions; you probably want to use -march=haswell or -march=x86-64-v3 instead of -mavx2"
-#    endif
-static_assert(ARCH_HASWELL_MACROS, "Undeclared identifiers indicate which features are missing.");
-#    define __haswell__       1
-#  endif
-#  undef ARCH_HASWELL_MACROS
 
 // x86-64 sub-architecture version 4
 //
@@ -228,15 +219,6 @@ static_assert(ARCH_HASWELL_MACROS, "Undeclared identif
 // 6th generation (codename "Skylake"). AMD Zen4 is the their first processor
 // with AVX512 support and it includes all of these too.
 //
-#  define ARCH_SKX_MACROS           (__AVX512F__ + __AVX512BW__ + __AVX512CD__ + __AVX512DQ__ + __AVX512VL__)
-#  if ARCH_SKX_MACROS != 0
-#    if ARCH_SKX_MACROS != 5
-#      error "Please enable all x86-64-v4 extensions; you probably want to use -march=skylake-avx512 or -march=x86-64-v4 instead of -mavx512f"
-#    endif
-static_assert(ARCH_SKX_MACROS, "Undeclared identifiers indicate which features are missing.");
-#    define __skylake_avx512__  1
-#  endif
-#  undef ARCH_SKX_MACROS
 #endif  /* Q_PROCESSOR_X86 */
 
 // NEON intrinsics

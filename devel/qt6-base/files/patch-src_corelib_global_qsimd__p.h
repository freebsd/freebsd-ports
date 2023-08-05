Fix build with CPUTYPE?=bdver[23].

It is incorrectly assumed here that all CPUs with FMA instruction sets
also have AVX2 instruction sets. This is true for Intel CPUs, but not
for AMD bdver[23] which have FMA, but not AVX2. All Intel and AMD CPUs
that have AVX2 also have BMI2, so use that as a check instead.

--- src/corelib/global/qsimd_p.h.orig	2023-08-05 14:03:16 UTC
+++ src/corelib/global/qsimd_p.h
@@ -226,7 +226,7 @@ asm(
 //
 // macOS's fat binaries support the "x86_64h" sub-architecture and the GNU libc
 // ELF loader also supports a "haswell/" subdir (e.g., /usr/lib/haswell).
-#  define ARCH_HASWELL_MACROS       (__AVX2__ + __FMA__)
+#  define ARCH_HASWELL_MACROS       (__AVX2__ + __BMI2__)
 #  if ARCH_HASWELL_MACROS != 0
 #    if ARCH_HASWELL_MACROS != 2
 #      error "Please enable all x86-64-v3 extensions; you probably want to use -march=haswell or -march=x86-64-v3 instead of -mavx2"

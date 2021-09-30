https://github.com/google/highway/commit/3769cb2c464c

--- third_party/highway/hwy/nanobenchmark.cc.orig	2021-06-09 08:56:32 UTC
+++ third_party/highway/hwy/nanobenchmark.cc
@@ -46,7 +46,7 @@
 #endif
 
 #include "hwy/base.h"
-#if HWY_ARCH_PPC
+#if HWY_ARCH_PPC && defined(__GLIBC__)
 #include <sys/platform/ppc.h>  // NOLINT __ppc_get_timebase_freq
 #elif HWY_ARCH_X86
 
@@ -119,7 +119,7 @@ using Ticks = uint64_t;
 // divide by InvariantTicksPerSecond.
 inline Ticks Start() {
   Ticks t;
-#if HWY_ARCH_PPC
+#if HWY_ARCH_PPC && defined(__GLIBC__)
   asm volatile("mfspr %0, %1" : "=r"(t) : "i"(268));
 #elif HWY_ARCH_X86 && HWY_COMPILER_MSVC
   _ReadWriteBarrier();
@@ -161,7 +161,7 @@ inline Ticks Start() {
 
 inline Ticks Stop() {
   uint64_t t;
-#if HWY_ARCH_PPC
+#if HWY_ARCH_PPC && defined(__GLIBC__)
   asm volatile("mfspr %0, %1" : "=r"(t) : "i"(268));
 #elif HWY_ARCH_X86 && HWY_COMPILER_MSVC
   _ReadWriteBarrier();
@@ -399,7 +399,7 @@ double NominalClockRate() {
 }  // namespace
 
 double InvariantTicksPerSecond() {
-#if HWY_ARCH_PPC
+#if HWY_ARCH_PPC && defined(__GLIBC__)
   return __ppc_get_timebase_freq();
 #elif HWY_ARCH_X86
   // We assume the TSC is invariant; it is on all recent Intel/AMD CPUs.

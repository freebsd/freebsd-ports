[Driver] Default to libc++ on FreeBSD

Downstream may naively translate between DSL and LLVM target
triple. If OS version is lost in the process then Clang would
default to a version that's no longer supported by OS vendor.

https://reviews.llvm.org/D77776

--- clang/lib/Driver/ToolChains/FreeBSD.cpp.orig	2021-06-28 16:23:38 UTC
+++ clang/lib/Driver/ToolChains/FreeBSD.cpp
@@ -466,6 +466,7 @@ bool FreeBSD::IsUnwindTablesDefault(const ArgList &Arg
 bool FreeBSD::isPIEDefault() const { return getSanitizerArgs().requiresPIE(); }
 
 SanitizerMask FreeBSD::getSupportedSanitizers() const {
+  const bool IsAArch64 = getTriple().getArch() == llvm::Triple::aarch64;
   const bool IsX86 = getTriple().getArch() == llvm::Triple::x86;
   const bool IsX86_64 = getTriple().getArch() == llvm::Triple::x86_64;
   const bool IsMIPS64 = getTriple().isMIPS64();
@@ -484,8 +485,13 @@ SanitizerMask FreeBSD::getSupportedSanitizers() const 
     Res |= SanitizerKind::Fuzzer;
     Res |= SanitizerKind::FuzzerNoLink;
   }
-  if (IsX86_64)
+  if (IsAArch64 || IsX86_64) {
+    Res |= SanitizerKind::KernelAddress;
+    Res |= SanitizerKind::KernelMemory;
+  }
+  if (IsX86_64) {
     Res |= SanitizerKind::Memory;
+  }
   return Res;
 }
 

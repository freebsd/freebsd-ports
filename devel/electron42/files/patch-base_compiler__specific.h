--- base/compiler_specific.h.orig	2025-06-30 07:04:30 UTC
+++ base/compiler_specific.h
@@ -733,6 +733,7 @@ inline constexpr bool AnalyzerAssumeTrue(bool arg) {
 #if __has_cpp_attribute(clang::preserve_most) &&             \
     (defined(ARCH_CPU_ARM64) || defined(ARCH_CPU_X86_64)) && \
     !defined(COMPONENT_BUILD) &&                             \
+    !BUILDFLAG(IS_OPENBSD) &&                                \
     !(BUILDFLAG(IS_WIN) && defined(ARCH_CPU_ARM64))
 #define PRESERVE_MOST [[clang::preserve_most]]
 #else

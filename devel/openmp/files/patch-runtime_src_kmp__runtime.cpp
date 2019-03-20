--- runtime/src/kmp_runtime.cpp.orig	2019-01-15 15:36:53 UTC
+++ runtime/src/kmp_runtime.cpp
@@ -8104,7 +8104,7 @@ __kmp_determine_reduction_method(
 
 #elif KMP_ARCH_X86 || KMP_ARCH_ARM || KMP_ARCH_AARCH || KMP_ARCH_MIPS
 
-#if KMP_OS_LINUX || KMP_OS_WINDOWS || KMP_OS_HURD
+#if KMP_OS_LINUX || KMP_OS_FREEBSD || KMP_OS_WINDOWS || KMP_OS_HURD
 
     // basic tuning
 

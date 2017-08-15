--- runtime/src/kmp_runtime.cpp.orig	2017-01-20 23:31:21 UTC
+++ runtime/src/kmp_runtime.cpp
@@ -7597,7 +7597,7 @@ __kmp_determine_reduction_method( ident_t *loc, kmp_in
 
         #elif KMP_ARCH_X86 || KMP_ARCH_ARM || KMP_ARCH_AARCH || KMP_ARCH_MIPS
 
-            #if KMP_OS_LINUX || KMP_OS_WINDOWS
+            #if KMP_OS_LINUX || KMP_OS_FREEBSD || KMP_OS_WINDOWS
 
                 // basic tuning
 

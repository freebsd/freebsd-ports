--- src/kmp_runtime.c.orig	2015-05-15 16:07:47 UTC
+++ src/kmp_runtime.c
@@ -7553,7 +7553,7 @@ __kmp_determine_reduction_method( ident_
 
         #elif KMP_ARCH_X86 || KMP_ARCH_ARM || KMP_ARCH_AARCH
 
-            #if KMP_OS_LINUX || KMP_OS_WINDOWS
+            #if KMP_OS_LINUX || KMP_OS_FREEBSD || KMP_OS_WINDOWS
 
                 // basic tuning
 

--- pfe/def-sbrcode.h.orig	2009-10-04 13:06:48 UTC
+++ pfe/def-sbrcode.h
@@ -35,7 +35,8 @@
 # if defined HOST_CPU_I386 || defined HOST_CPU_I486 \
   || defined HOST_CPU_I586 || defined HOST_CPU_I686 \
   || defined HOST_ARCH_I386 || defined __target_arch_i386 \
-  || defined HOST_ARCH_X86_64 || defined HOST_CPU_X86_64
+  || defined HOST_ARCH_X86_64 || defined HOST_CPU_X86_64 \
+  || defined HOST_ARCH_AMD64
 
 # if defined HOST_ARCH_X86_64 || defined HOST_CPU_X86_64
 # define PFE_SBR_ARCH_I386_64 1
@@ -172,9 +173,9 @@
 #  define PFE_SBR_DECOMPILE_BCOMMA 1
 
 /* ======================================================== ARCH_POWERPC === */
-# elif defined HOST_OS_AIX3 || defined HOST_CPU_POWERPC \
+# elif (defined HOST_OS_AIX3 || defined HOST_CPU_POWERPC \
     || defined __target_os_aix3 || defined __target_cpu_powerpc \
-    || defined HOST_ARCH_POWERPC
+    || defined HOST_ARCH_POWERPC) && !defined __powerpc64__
 
 #   define PFE_SBR_ARCH_POWERPC 1
 #   define PFE_SBR_ARCH "powerpc"

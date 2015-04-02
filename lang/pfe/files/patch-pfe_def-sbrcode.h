--- pfe/def-sbrcode.h.orig	2015-03-31 14:14:01.000000000 +0200
+++ pfe/def-sbrcode.h	2015-03-31 14:15:23.000000000 +0200
@@ -35,7 +35,8 @@
 # if defined HOST_CPU_I386 || defined HOST_CPU_I486 \
   || defined HOST_CPU_I586 || defined HOST_CPU_I686 \
   || defined HOST_ARCH_I386 || defined __target_arch_i386 \
-  || defined HOST_ARCH_X86_64 || defined HOST_CPU_X86_64
+  || defined HOST_ARCH_X86_64 || defined HOST_CPU_X86_64 \
+  || defined HOST_ARCH_AMD64
 
 # if defined HOST_ARCH_X86_64 || defined HOST_CPU_X86_64
 # define PFE_SBR_ARCH_I386_64 1

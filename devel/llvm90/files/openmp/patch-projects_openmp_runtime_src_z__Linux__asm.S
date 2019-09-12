--- projects/openmp/runtime/src/z_Linux_asm.S.orig	2019-07-02 13:45:40 UTC
+++ projects/openmp/runtime/src/z_Linux_asm.S
@@ -1328,12 +1328,12 @@ KMP_LABEL(kmp_1):
 // return:	r3	(always 1/TRUE)
 //
 	.text
-# if KMP_ARCH_PPC64_LE
+# if KMP_ARCH_PPC64_ELFv2
 	.abiversion 2
 # endif
 	.globl	__kmp_invoke_microtask
 
-# if KMP_ARCH_PPC64_LE
+# if KMP_ARCH_PPC64_ELFv2
 	.p2align	4
 # else
 	.p2align	2
@@ -1341,7 +1341,7 @@ KMP_LABEL(kmp_1):
 
 	.type	__kmp_invoke_microtask,@function
 
-# if KMP_ARCH_PPC64_LE
+# if KMP_ARCH_PPC64_ELFv2
 __kmp_invoke_microtask:
 .Lfunc_begin0:
 .Lfunc_gep0:
@@ -1385,7 +1385,7 @@ __kmp_invoke_microtask:
 	.cfi_offset lr, 16
 
 // Compute the size necessary for the local stack frame.
-# if KMP_ARCH_PPC64_LE
+# if KMP_ARCH_PPC64_ELFv2
 	li 12, 72
 # else
 	li 12, 88
@@ -1463,7 +1463,7 @@ __kmp_invoke_microtask:
 // for the microtask begins 48 + 8*8 == 112 bytes above r1 for ELFv1 and
 // 32 + 8*8 == 96 bytes above r1 for ELFv2.
 	addi 4, 4, 40
-# if KMP_ARCH_PPC64_LE
+# if KMP_ARCH_PPC64_ELFv2
 	addi 12, 1, 88
 # else
 	addi 12, 1, 104
@@ -1475,7 +1475,7 @@ __kmp_invoke_microtask:
 	bdnz .Lnext
 
 .Lcall:
-# if KMP_ARCH_PPC64_LE
+# if KMP_ARCH_PPC64_ELFv2
 	std 2, 24(1)
 	mr 12, 3
 #else
@@ -1491,7 +1491,7 @@ __kmp_invoke_microtask:
 
 	mtctr 12
 	bctrl
-# if KMP_ARCH_PPC64_LE
+# if KMP_ARCH_PPC64_ELFv2
 	ld 2, 24(1)
 # else
 	ld 2, 40(1)

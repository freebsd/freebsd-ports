--- third_party/boringssl/src/crypto/fipsmodule/bn/asm/x86_64-mont5.pl.orig	2023-08-10 01:51:10 UTC
+++ third_party/boringssl/src/crypto/fipsmodule/bn/asm/x86_64-mont5.pl
@@ -79,6 +79,7 @@ $code=<<___;
 .align	64
 bn_mul_mont_gather5:
 .cfi_startproc
+	_CET_ENDBR
 	mov	${num}d,${num}d
 	mov	%rsp,%rax
 .cfi_def_cfa_register	%rax
@@ -1098,6 +1099,7 @@ $code.=<<___;
 .align	32
 bn_power5:
 .cfi_startproc
+	_CET_ENDBR
 	mov	%rsp,%rax
 .cfi_def_cfa_register	%rax
 ___
@@ -1240,6 +1242,7 @@ $code.=<<___;
 bn_sqr8x_internal:
 __bn_sqr8x_internal:
 .cfi_startproc
+	_CET_ENDBR
 	##############################################################
 	# Squaring part:
 	#
@@ -2737,6 +2740,7 @@ bn_powerx5:
 bn_sqrx8x_internal:
 __bn_sqrx8x_internal:
 .cfi_startproc
+	_CET_ENDBR
 	##################################################################
 	# Squaring part:
 	#
@@ -3448,6 +3452,7 @@ $code.=<<___;
 .align	16
 bn_scatter5:
 .cfi_startproc
+	_CET_ENDBR
 	cmp	\$0, $num
 	jz	.Lscatter_epilogue
 
@@ -3478,6 +3483,7 @@ bn_scatter5:
 bn_gather5:
 .cfi_startproc
 .LSEH_begin_bn_gather5:			# Win64 thing, but harmless in other cases
+	_CET_ENDBR
 	# I can't trust assembler to use specific encoding:-(
 	.byte	0x4c,0x8d,0x14,0x24			#lea    (%rsp),%r10
 .cfi_def_cfa_register	%r10

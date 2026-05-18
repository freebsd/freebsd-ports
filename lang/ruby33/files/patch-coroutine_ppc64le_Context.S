--- coroutine/ppc64le/Context.S.orig	2025-11-17 12:39:04 UTC
+++ coroutine/ppc64le/Context.S
@@ -1,11 +1,19 @@
 #define TOKEN_PASTE(x,y) x##y
 
+.abiversion 2
+
 .text
 .align 2
 
 .globl PREFIXED_SYMBOL(coroutine_transfer)
 .type   PREFIXED_SYMBOL(coroutine_transfer), @function
 PREFIXED_SYMBOL(coroutine_transfer):
+	# Global entry: set up TOC pointer (r2) from r12.
+	# Required by ELFv2 ABI when this function is reached via the PLT.
+	addis 2, 12, .TOC. - PREFIXED_SYMBOL(coroutine_transfer)@ha
+	addi  2, 2,  .TOC. - PREFIXED_SYMBOL(coroutine_transfer)@l
+	.localentry PREFIXED_SYMBOL(coroutine_transfer), .-PREFIXED_SYMBOL(coroutine_transfer)
+
 	# Make space on the stack for caller registers
 	addi 1,1,-160
 

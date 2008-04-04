--- src/arm/sysv.S.orig	2008-02-15 02:15:41.000000000 +0100
+++ src/arm/sysv.S	2008-04-01 13:25:02.000000000 +0200
@@ -83,14 +83,6 @@
 # define call_reg(x)	mov	lr, pc ; mov	pc, x
 #endif
 
-/* Conditionally compile unwinder directives.  */
-#ifdef __ARM_EABI__
-#define UNWIND
-#else
-#define UNWIND @
-#endif	
-
-	
 #if defined(__thumb__) && !defined(__THUMB_INTERWORK__)
 .macro	ARM_FUNC_START name
 	.text
@@ -101,7 +93,6 @@
 	bx	pc
 	nop
 	.arm
-	UNWIND .fnstart
 /* A hook to tell gdb that we've switched to ARM mode.  Also used to call
    directly from other local arm routines.  */
 _L__\name:		
@@ -112,7 +103,6 @@
 	.align 0
 	.arm
 	ENTRY(\name)
-	UNWIND .fnstart
 .endm
 #endif
 
@@ -145,11 +135,8 @@
 ARM_FUNC_START ffi_call_SYSV
 	@ Save registers
         stmfd	sp!, {r0-r3, fp, lr}
-	UNWIND .save	{r0-r3, fp, lr}
 	mov	fp, sp
 
-	UNWIND .setfp	fp, sp
-
 	@ Make room for all of the new args.
 	sub	sp, fp, r2
 
@@ -219,7 +206,6 @@
 	RETLDM	"r0-r3,fp"
 
 .ffi_call_SYSV_end:
-	UNWIND .fnend
         .size    CNAME(ffi_call_SYSV),.ffi_call_SYSV_end-CNAME(ffi_call_SYSV)
 
 /*
@@ -231,12 +217,9 @@
 */
 
 ARM_FUNC_START ffi_closure_SYSV
-	UNWIND .pad #16
 	add	ip, sp, #16
 	stmfd	sp!, {ip, lr}
-	UNWIND .save	{r0, lr}
 	add	r2, sp, #8
-	.pad #16
 	sub	sp, sp, #16
 	str	sp, [sp, #8]
 	add	r1, sp, #8
@@ -291,6 +274,5 @@
 #endif
 
 .ffi_closure_SYSV_end:
-	UNWIND .fnend
         .size    CNAME(ffi_closure_SYSV),.ffi_closure_SYSV_end-CNAME(ffi_closure_SYSV)
 

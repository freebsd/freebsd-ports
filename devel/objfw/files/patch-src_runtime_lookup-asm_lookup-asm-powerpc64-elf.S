--- src/runtime/lookup-asm/lookup-asm-powerpc64-elf.S.orig	2026-08-02 17:00:57 UTC
+++ src/runtime/lookup-asm/lookup-asm-powerpc64-elf.S
@@ -93,8 +93,8 @@
 	xor	%r5, %r3, %r5
 	rlwinm	%r5, %r5, 2, 0x38
 
-	addis	%r6, %r2, _objc_taggedPointerClasses@toc@ha
-	addi	%r6, %r6, _objc_taggedPointerClasses@toc@l
+	addis	%r6, %r2, _objc_taggedPointerClasses@got@ha
+	ld	%r6, _objc_taggedPointerClasses@got@l(%r6)
 	ldx	%r5, %r6, %r5
 	ld	%r5, 64(%r5)
 

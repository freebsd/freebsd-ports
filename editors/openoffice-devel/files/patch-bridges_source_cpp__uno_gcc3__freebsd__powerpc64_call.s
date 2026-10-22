--- bridges/source/cpp_uno/gcc3_freebsd_powerpc64/call.s.orig	2026-09-18 00:49:04 UTC
+++ bridges/source/cpp_uno/gcc3_freebsd_powerpc64/call.s
@@ -56,9 +56,6 @@ callVirtualMethod:
 	stw 9,296(31)
 	ld 9,304(31)
 	std 9,96(31)
-	ld 9,-28688(13)
-	std 9,184(31)
-	li 9,0
 	lwz 9,280(31)
 	cmpwi 0,9,0
 	beq 0,.L2
@@ -190,22 +187,14 @@ callVirtualMethod:
 	mr 9,3
 	mr 10,4
 	lfd 0,152(31)
-	ld 7,128(31)
-	ld 6,120(31)
+	ld 6,128(31)
+	ld 5,120(31)
 	fmr 1,0
 	mr 4,10
 	mr 3,9
 	bl MapReturn
 	nop
 	nop
-	ld 9,184(31)
-	ld 10,-28688(13)
-	xor. 9,9,10
-	li 10,0
-	beq 0,.L5
-	bl __stack_chk_fail
-	nop
-.L5:
 	addi 1,31,208
 	.cfi_def_cfa 1, 0
 	ld 0,16(1)
@@ -241,9 +230,6 @@ privateSnippetExecutor:
 	.cfi_offset 31, -8
 	mr 31,1
 	.cfi_def_cfa_register 31
-	ld 0,-28688(13)
-	std 0,248(31)
-	li 0,0
 	std 3,80(31)
 	std 4,88(31)
 	std 5,96(31)
@@ -287,6 +273,8 @@ stfd 13, 96(9)
 	mr 9,3
 	stw 9,44(31)
 	lwa 9,44(31)
+	cmpwi 0,9,100
+	beq 0,.Lfprs
 	cmplwi 0,9,15
 	bgt 0,.L7
 	sldi 10,9,2
@@ -388,18 +376,20 @@ stfd 13, 96(9)
  # 0 "" 2
 #NO_APP
 	b .L17
+.Lfprs:
+	lfd 1,144(31)
+	lfd 2,152(31)
+	lfd 3,160(31)
+	lfd 4,168(31)
+	lfd 5,176(31)
+	lfd 6,184(31)
+	lfd 7,192(31)
+	lfd 8,200(31)
+	b .L17
 .L19:
 	nop
 .L17:
 	nop
-	ld 9,248(31)
-	ld 10,-28688(13)
-	xor. 9,9,10
-	li 10,0
-	beq 0,.L18
-	bl __stack_chk_fail
-	nop
-.L18:
 	addi 1,31,272
 	.cfi_def_cfa 1, 0
 	ld 0,16(1)

--- ./newlib/libc/sys/psp/interrupt.S.orig	2012-01-25 19:33:12.000000000 +0000
+++ ./newlib/libc/sys/psp/interrupt.S	2012-01-25 19:33:12.000000000 +0000
@@ -0,0 +1,66 @@
+
+	.set noreorder
+	.set noat
+
+	.global pspDisableInterrupts
+	.ent    pspDisableInterrupts
+
+pspDisableInterrupts:
+	mfic	$v0, $0
+	mtic	$0, $0
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	jr		$ra
+	nop
+
+	.end pspDisableInterrupts
+
+	.global pspEnableInterrupts
+	.ent    pspEnableInterrupts
+
+pspEnableInterrupts:
+	mtic	$a0, $0
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	nop
+	jr		$ra
+	nop
+
+	.end pspEnableInterrupts

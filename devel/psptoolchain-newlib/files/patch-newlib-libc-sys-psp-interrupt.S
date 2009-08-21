--- newlib/libc/sys/psp/interrupt.S.orig	1970-01-01 02:00:00.000000000 +0200
+++ newlib/libc/sys/psp/interrupt.S	2007-06-01 12:22:26.000000000 +0300
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

$NetBSD: patch-ai,v 1.1 2003/03/08 03:15:52 jmc Exp $

--- osdll/DrvSystem_ppc-gcc.s.orig	Fri Apr  5 21:29:15 2002
+++ osdll/DrvSystem_ppc-gcc.s	Fri Apr  5 21:29:27 2002
@@ -61,7 +61,7 @@
 	mr	SP,r3
 # gcc/gas breaks on this
 #	bl	.TWIN_InitStackEnd{PR}
-	bl	TWIN_InitStackEnd
+	bl	TWIN_InitStackEnd@plt
 	nop
 	nop
 	nop

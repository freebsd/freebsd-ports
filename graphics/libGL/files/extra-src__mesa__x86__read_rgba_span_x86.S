--- ./src/mesa/x86/read_rgba_span_x86.S.orig	2008-08-25 16:46:47.000000000 +0200
+++ ./src/mesa/x86/read_rgba_span_x86.S	2011-01-28 18:10:06.000000000 +0100
@@ -648,7 +648,7 @@ _generic_read_RGBA_span_RGB565_MMX:
 	testl	$0x01, %ecx
 	je	.L01
 
-	movzxw	(%eax), %ecx
+	movzwl	(%eax), %ecx
 	movd	%ecx, %mm4
 
 	pshufw	$0x00, %mm4, %mm0

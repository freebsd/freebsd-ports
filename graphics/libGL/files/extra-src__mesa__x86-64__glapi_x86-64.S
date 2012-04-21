--- ./src/mesa/x86-64/glapi_x86-64.S.orig	2009-03-13 04:28:49.000000000 +0100
+++ ./src/mesa/x86-64/glapi_x86-64.S	2011-01-28 18:12:18.000000000 +0100
@@ -73,7 +73,8 @@ _x86_64_get_dispatch:
 
 	.p2align	4,,15
 _x86_64_get_dispatch:
-	movq	_gl_DispatchTSD(%rip), %rdi
+	movq	_gl_DispatchTSD@GOTPCREL(%rip), %rax
+	movl	(%rax), %edi
 	jmp	pthread_getspecific@PLT
 
 #elif defined(THREADS)

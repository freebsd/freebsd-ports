--- src/swtch.s.orig	Thu Nov  6 06:03:00 1997
+++ src/swtch.s	Tue Jun  8 21:44:42 1999
@@ -1,4 +1,4 @@
-#if alpha
+#if __alpha
 .globl	_swtch
 .ent	_swtch
 _swtch:	lda	$sp,-112($sp)	# allocate _swtch's frame
@@ -39,9 +39,10 @@
 	lda	$sp,112($sp)	# deallocate frame
 	ret	$31,($26)
 .end	_swtch
-.globl	_start
-.ent	_start
-_start:	.frame	$sp,0,$26
+.globl	_thrstart
+.ent	_thrstart
+_thrstart:
+	.frame	$sp,0,$26
 	.mask	0x0,0
 	.prologue 0
 	mov	$14,$16	# register 14 holds args
@@ -52,7 +53,7 @@
 	mov	$13,$27	# register 13 has Thread_exit
 	jsr	$26,($27)
 	call_pal	0
-.end	_start
+.end	_thrstart
 .globl	_ENDMONITOR
 _ENDMONITOR:
 #elif sparc
@@ -136,7 +137,7 @@
 .end	_swtch
 .globl	_ENDMONITOR
 _ENDMONITOR:
-#elif linux && i386
+#elif (linux || unix) && i386
 .align	4
 .globl	__swtch
 .globl	_swtch
@@ -165,7 +166,11 @@
 	pushl	%edi
 	call	*%esi
 	pushl	%eax
+#ifdef __ELF__
 	call	Thread_exit
+#else
+	call	_Thread_exit
+#endif
 .globl	__ENDMONITOR
 .globl	_ENDMONITOR
 __ENDMONITOR:

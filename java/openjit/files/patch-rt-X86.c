$FreeBSD$

--- rt-X86.c.orig	Thu Oct 16 20:16:17 2003
+++ rt-X86.c	Thu Oct 16 20:22:19 2003
@@ -127,14 +127,14 @@
 #define ASM __asm__ volatile
 
 #ifdef SYM_UNDERSCORE
-__asm__("
-_OpenJIT_f2i = OpenJIT_f2i
-_OpenJIT_d2i = OpenJIT_f2i
-_OpenJIT_f2l = OpenJIT_f2l
-_OpenJIT_d2l = OpenJIT_d2l
-_OpenJIT_invokeinterface_quick = OpenJIT_invokeinterface_quick
-_throw_internal = throw_internal
-");
+__asm__(
+"_OpenJIT_f2i = OpenJIT_f2i\n"
+"_OpenJIT_d2i = OpenJIT_f2i\n"
+"_OpenJIT_f2l = OpenJIT_f2l\n"
+"_OpenJIT_d2l = OpenJIT_d2l\n"
+"_OpenJIT_invokeinterface_quick = OpenJIT_invokeinterface_quick\n"
+"_throw_internal = throw_internal\n"
+);
 #define ASM_TEXT_LABEL(X) __asm__(".text\n_" #X ":\n");
 #else
 #define ASM_TEXT_LABEL(X) __asm__(".text\n" #X ":\n");
@@ -2051,107 +2051,107 @@
 extern int OpenJIT_d2i();	/* One arg is passed via floating ST(0) */
 extern int64_t OpenJIT_f2l(float f);
 extern int64_t OpenJIT_d2l(double d);
-__asm__("
-OpenJIT_d2i = OpenJIT_f2i
-.text
-	.align 4
-	.type	 OpenJIT_f2i,@function
-OpenJIT_f2i:
-	pushl %ebp
-	movl %esp,%ebp
-	subl $8,%esp
-	ftst
-	fnstcw -4(%ebp)
-	movl -4(%ebp),%eax
-	movb $0xc,%ah
-	movw %ax,-2(%ebp)
-	fldcw -2(%ebp)
-	fistpl -8(%ebp)
-	fldcw -4(%ebp)
-	movl -8(%ebp),%eax
-	cmp $0x80000000,%eax
-	je IntOverFlow
-	leave
-	ret
-
-IntOverFlow:
-	fnstsw
-	sahf
-	jp	IntNaN
-	movl	$0x80000000,%eax
-	adcl	$-1,%eax
-	leave
-	ret
-IntNaN:
-	xorl	%eax,%eax
-	leave
-	ret
-
-.text
-	.align 4
-	.type	 OpenJIT_f2l,@function
-OpenJIT_f2l:
-	pushl %ebp
-	movl %esp,%ebp
-	subl $12,%esp
-	flds 8(%ebp)
-	ftst
-	fnstcw -4(%ebp)
-	movl -4(%ebp),%eax
-	movb $0xc,%ah
-	movw %ax,-2(%ebp)
-	fldcw -2(%ebp)
-	fistpll -12(%ebp)
-	fldcw -4(%ebp)
-	movl -12(%ebp),%eax
-	movl $0x80000000,%ecx
-	movl -8(%ebp),%edx
-	xorl %edx,%ecx
-	orl %eax,%ecx
-	je LongOverFlow
-	leave
-	ret
-
-	.align 4
-	.type	 OpenJIT_d2l,@function
-OpenJIT_d2l:
-	pushl %ebp
-	movl %esp,%ebp
-	subl $12,%esp
-	fldl 8(%ebp)
-	ftst
-	fnstcw -4(%ebp)
-	movl -4(%ebp),%eax
-	movb $0xc,%ah
-	movw %ax,-2(%ebp)
-	fldcw -2(%ebp)
-	fistpll -12(%ebp)
-	fldcw -4(%ebp)
-	movl -12(%ebp),%eax
-	movl $0x80000000,%ecx
-	movl -8(%ebp),%edx
-	xorl %edx,%ecx
-	orl %eax,%ecx
-	je LongOverFlow
-	leave
-	ret
-
-LongOverFlow:
-	fnstsw
-	sahf
-	jp	LongNaN
-	movl	$0,%eax
-	adcl	$-1,%eax
-	adcl	$-1,%edx
-	leave
-	ret
-
-LongNaN:
-	xorl	%eax,%eax
-	xorl	%edx,%edx
-	leave
-	ret
-");
+__asm__(
+"OpenJIT_d2i = OpenJIT_f2i\n"
+".text\n"
+"	.align 4\n"
+"	.type	 OpenJIT_f2i,@function\n"
+"OpenJIT_f2i:\n"
+"	pushl %ebp\n"
+"	movl %esp,%ebp\n"
+"	subl $8,%esp\n"
+"	ftst\n"
+"	fnstcw -4(%ebp)\n"
+"	movl -4(%ebp),%eax\n"
+"	movb $0xc,%ah\n"
+"	movw %ax,-2(%ebp)\n"
+"	fldcw -2(%ebp)\n"
+"	fistpl -8(%ebp)\n"
+"	fldcw -4(%ebp)\n"
+"	movl -8(%ebp),%eax\n"
+"	cmp $0x80000000,%eax\n"
+"	je IntOverFlow\n"
+"	leave\n"
+"	ret\n"
+"\n"
+"IntOverFlow:\n"
+"	fnstsw\n"
+"	sahf\n"
+"	jp	IntNaN\n"
+"	movl	$0x80000000,%eax\n"
+"	adcl	$-1,%eax\n"
+"	leave\n"
+"	ret\n"
+"IntNaN:\n"
+"	xorl	%eax,%eax\n"
+"	leave\n"
+"	ret\n"
+"\n"
+".text\n"
+"	.align 4\n"
+"	.type	 OpenJIT_f2l,@function\n"
+"OpenJIT_f2l:\n"
+"	pushl %ebp\n"
+"	movl %esp,%ebp\n"
+"	subl $12,%esp\n"
+"	flds 8(%ebp)\n"
+"	ftst\n"
+"	fnstcw -4(%ebp)\n"
+"	movl -4(%ebp),%eax\n"
+"	movb $0xc,%ah\n"
+"	movw %ax,-2(%ebp)\n"
+"	fldcw -2(%ebp)\n"
+"	fistpll -12(%ebp)\n"
+"	fldcw -4(%ebp)\n"
+"	movl -12(%ebp),%eax\n"
+"	movl $0x80000000,%ecx\n"
+"	movl -8(%ebp),%edx\n"
+"	xorl %edx,%ecx\n"
+"	orl %eax,%ecx\n"
+"	je LongOverFlow\n"
+"	leave\n"
+"	ret\n"
+"\n"
+"	.align 4\n"
+"	.type	 OpenJIT_d2l,@function\n"
+"OpenJIT_d2l:\n"
+"	pushl %ebp\n"
+"	movl %esp,%ebp\n"
+"	subl $12,%esp\n"
+"	fldl 8(%ebp)\n"
+"	ftst\n"
+"	fnstcw -4(%ebp)\n"
+"	movl -4(%ebp),%eax\n"
+"	movb $0xc,%ah\n"
+"	movw %ax,-2(%ebp)\n"
+"	fldcw -2(%ebp)\n"
+"	fistpll -12(%ebp)\n"
+"	fldcw -4(%ebp)\n"
+"	movl -12(%ebp),%eax\n"
+"	movl $0x80000000,%ecx\n"
+"	movl -8(%ebp),%edx\n"
+"	xorl %edx,%ecx\n"
+"	orl %eax,%ecx\n"
+"	je LongOverFlow\n"
+"	leave\n"
+"	ret\n"
+"\n"
+"LongOverFlow:\n"
+"	fnstsw\n"
+"	sahf\n"
+"	jp	LongNaN\n"
+"	movl	$0,%eax\n"
+"	adcl	$-1,%eax\n"
+"	adcl	$-1,%edx\n"
+"	leave\n"
+"	ret\n"
+"\n"
+"LongNaN:\n"
+"	xorl	%eax,%eax\n"
+"	xorl	%edx,%edx\n"
+"	leave\n"
+"	ret\n"
+);
 
 static int64_t
 OpenJIT_lshr(int64_t ll, unsigned b)
@@ -2383,16 +2383,16 @@
 }
 
 extern void throw_internal();
-__asm__("
-.text
-	.align 4
-	.type	 throw_internal,@function
-throw_internal:
-	pushl %eax
-	jmp   *%edx
-.Lfe_throw_internal:
-	.size	 throw_internal,.Lfe_throw_internal-throw_internal
-");
+__asm__(
+".text\n"
+"	.align 4\n"
+"	.type	 throw_internal,@function\n"
+"throw_internal:\n"
+"	pushl %eax\n"
+"	jmp   *%edx\n"
+".Lfe_throw_internal:\n"
+"	.size	 throw_internal,.Lfe_throw_internal-throw_internal\n"
+);
 
 #if defined(__linux__)
 static int signal_nest_count = -1;

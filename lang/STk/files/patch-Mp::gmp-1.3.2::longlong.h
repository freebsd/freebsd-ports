--- Mp/gmp-1.3.2/longlong.h.orig	Mon Jul 28 20:38:34 2003
+++ Mp/gmp-1.3.2/longlong.h	Mon Jul 28 21:26:27 2003
@@ -91,7 +91,7 @@
 
 #if defined (__a29k__) || defined (___AM29K__)
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("add %1,%4,%5
+  __asm__ ("add %1,%4,%5\n\
 	addc %0,%2,%3"							\
 	   : "=r" ((unsigned long int)(sh)),				\
 	    "=&r" ((unsigned long int)(sl))				\
@@ -100,7 +100,7 @@
 	     "%r" ((unsigned long int)(al)),				\
 	     "rI" ((unsigned long int)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("sub %1,%4,%5
+  __asm__ ("sub %1,%4,%5\n\
 	subc %0,%2,%3"							\
 	   : "=r" ((unsigned long int)(sh)),				\
 	     "=&r" ((unsigned long int)(sl))				\
@@ -149,7 +149,7 @@
 
 #if defined (__arm__)
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("adds %1,%4,%5
+  __asm__ ("adds %1,%4,%5\n\
 	adc %0,%2,%3"							\
 	   : "=r" ((unsigned long int)(sh)),				\
 	     "=&r" ((unsigned long int)(sl))				\
@@ -158,7 +158,7 @@
 	     "%r" ((unsigned long int)(al)),				\
 	     "rI" ((unsigned long int)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("subs %1,%4,%5
+  __asm__ ("subs %1,%4,%5\n\
 	sbc %0,%2,%3"							\
 	   : "=r" ((unsigned long int)(sh)),				\
 	     "=&r" ((unsigned long int)(sl))				\
@@ -170,7 +170,7 @@
 
 #if defined (__gmicro__)
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("add.w %5,%1
+  __asm__ ("add.w %5,%1\n\
 	addx %3,%0"							\
 	   : "=g" ((unsigned long int)(sh)),				\
 	     "=&g" ((unsigned long int)(sl))				\
@@ -179,7 +179,7 @@
 	     "%1" ((unsigned long int)(al)),				\
 	     "g" ((unsigned long int)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("sub.w %5,%1
+  __asm__ ("sub.w %5,%1\n\
 	subx %3,%0"							\
 	   : "=g" ((unsigned long int)(sh)),				\
 	     "=&g" ((unsigned long int)(sl))				\
@@ -209,7 +209,7 @@
 
 #if defined (__hppa)
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("add %4,%5,%1
+  __asm__ ("add %4,%5,%1\n\
 	addc %2,%3,%0"							\
 	   : "=r" ((unsigned long int)(sh)),				\
 	     "=&r" ((unsigned long int)(sl))				\
@@ -218,7 +218,7 @@
 	     "%rM" ((unsigned long int)(al)),				\
 	     "rM" ((unsigned long int)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("sub %4,%5,%1
+  __asm__ ("sub %4,%5,%1\n\
 	subb %2,%3,%0"							\
 	   : "=r" ((unsigned long int)(sh)),				\
 	     "=&r" ((unsigned long int)(sl))				\
@@ -249,28 +249,28 @@
   do {									\
     unsigned long int __tmp;						\
     __asm__ (								\
-       "ldi		1,%0
-	extru,=		%1,15,16,%%r0		; Bits 31..16 zero?
-	extru,tr	%1,15,16,%1		; No.  Shift down, skip add.
-	ldo		16(%0),%0		; Yes.  Perform add.
-	extru,=		%1,23,8,%%r0		; Bits 15..8 zero?
-	extru,tr	%1,23,8,%1		; No.  Shift down, skip add.
-	ldo		8(%0),%0		; Yes.  Perform add.
-	extru,=		%1,27,4,%%r0		; Bits 7..4 zero?
-	extru,tr	%1,27,4,%1		; No.  Shift down, skip add.
-	ldo		4(%0),%0		; Yes.  Perform add.
-	extru,=		%1,29,2,%%r0		; Bits 3..2 zero?
-	extru,tr	%1,29,2,%1		; No.  Shift down, skip add.
-	ldo		2(%0),%0		; Yes.  Perform add.
-	extru		%1,30,1,%1		; Extract bit 1.
-	sub		%0,%1,%0		; Subtract it.
+       "ldi		1,%0\n\
+	extru,=		%1,15,16,%%r0		; Bits 31..16 zero?\n\
+	extru,tr	%1,15,16,%1		; No.  Shift down, skip add.\n\
+	ldo		16(%0),%0		; Yes.  Perform add.\n\
+	extru,=		%1,23,8,%%r0		; Bits 15..8 zero?\n\
+	extru,tr	%1,23,8,%1		; No.  Shift down, skip add.\n\
+	ldo		8(%0),%0		; Yes.  Perform add.\n\
+	extru,=		%1,27,4,%%r0		; Bits 7..4 zero?\n\
+	extru,tr	%1,27,4,%1		; No.  Shift down, skip add.\n\
+	ldo		4(%0),%0		; Yes.  Perform add.\n\
+	extru,=		%1,29,2,%%r0		; Bits 3..2 zero?\n\
+	extru,tr	%1,29,2,%1		; No.  Shift down, skip add.\n\
+	ldo		2(%0),%0		; Yes.  Perform add.\n\
+	extru		%1,30,1,%1		; Extract bit 1.\n\
+	sub		%0,%1,%0		; Subtract it.\
 	" : "=r" (count), "=r" (__tmp) : "1" (x));			\
   } while (0)
 #endif
 
 #if defined (__i386__) || defined (__i486__)
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("addl %5,%1
+  __asm__ ("addl %5,%1\n\
 	adcl %3,%0"							\
 	   : "=r" ((unsigned long int)(sh)),				\
 	     "=&r" ((unsigned long int)(sl))				\
@@ -279,7 +279,7 @@
 	     "%1" ((unsigned long int)(al)),				\
 	     "g" ((unsigned long int)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("subl %5,%1
+  __asm__ ("subl %5,%1\n\
 	sbbl %3,%0"							\
 	   : "=r" ((unsigned long int)(sh)),				\
 	     "=&r" ((unsigned long int)(sl))				\
@@ -367,7 +367,7 @@
 
 #if defined (___IBMR2__) /* IBM RS6000 */
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("a%I5 %1,%4,%5
+  __asm__ ("a%I5 %1,%4,%5\n\
 	ae %0,%2,%3"							\
 	   : "=r" ((unsigned long int)(sh)),				\
 	     "=&r" ((unsigned long int)(sl))				\
@@ -376,7 +376,7 @@
 	     "%r" ((unsigned long int)(al)),				\
 	     "rI" ((unsigned long int)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("sf%I4 %1,%5,%4
+  __asm__ ("sf%I4 %1,%5,%4\n\
 	sfe %0,%3,%2"							\
 	   : "=r" ((unsigned long int)(sh)),				\
 	     "=&r" ((unsigned long int)(sl))				\
@@ -415,7 +415,7 @@
 
 #if defined (__mc68000__)
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("add%.l %5,%1
+  __asm__ ("add%.l %5,%1\n\
 	addx%.l %3,%0"							\
 	   : "=d" ((unsigned long int)(sh)),				\
 	     "=&d" ((unsigned long int)(sl))				\
@@ -424,7 +424,7 @@
 	     "%1" ((unsigned long int)(al)),				\
 	     "g" ((unsigned long int)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("sub%.l %5,%1
+  __asm__ ("sub%.l %5,%1\n\
 	subx%.l %3,%0"							\
 	   : "=d" ((unsigned long int)(sh)),				\
 	     "=&d" ((unsigned long int)(sl))				\
@@ -463,31 +463,31 @@
 /* This ought to be improved by relying on reload to move inputs and
    outputs to their positions.  */
 #define umul_ppmm(xh, xl, a, b) \
-  __asm__ ("| Inlined umul_ppmm
-	movel	%2,d0
-	movel	%3,d1
-	movel	d0,d2
-	swap	d0
-	movel	d1,d3
-	swap	d1
-	movew	d2,d4
-	mulu	d3,d4
-	mulu	d1,d2
-	mulu	d0,d3
-	mulu	d0,d1
-	movel	d4,d0
-	eorw	d0,d0
-	swap	d0
-	addl	d0,d2
-	addl	d3,d2
-	jcc	1f
-	addl	#65536,d1
-1:	swap	d2
-	moveq	#0,d0
-	movew	d2,d0
-	movew	d4,d2
-	movel	d2,%1
-	addl	d1,d0
+  __asm__ ("| Inlined umul_ppmm\n\
+	movel	%2,d0\n\
+	movel	%3,d1\n\
+	movel	d0,d2\n\
+	swap	d0\n\
+	movel	d1,d3\n\
+	swap	d1\n\
+	movew	d2,d4\n\
+	mulu	d3,d4\n\
+	mulu	d1,d2\n\
+	mulu	d0,d3\n\
+	mulu	d0,d1\n\
+	movel	d4,d0\n\
+	eorw	d0,d0\n\
+	swap	d0\n\
+	addl	d0,d2\n\
+	addl	d3,d2\n\
+	jcc	1f\n\
+	addl	#65536,d1\n\
+1:	swap	d2\n\
+	moveq	#0,d0\n\
+	movew	d2,d0\n\
+	movew	d4,d2\n\
+	movel	d2,%1\n\
+	addl	d1,d0\n\
 	movel	d0,%0"							\
 	   : "=g" ((unsigned long int)(xh)),				\
 	     "=g" ((unsigned long int)(xl))				\
@@ -501,7 +501,7 @@
 
 #if defined (__m88000__)
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("addu.co %1,%r4,%r5
+  __asm__ ("addu.co %1,%r4,%r5\n\
 	addu.ci %0,%r2,%r3"						\
 	   : "=r" ((unsigned long int)(sh)),				\
 	     "=&r" ((unsigned long int)(sl))				\
@@ -510,7 +510,7 @@
 	     "%rJ" ((unsigned long int)(al)),				\
 	     "rJ" ((unsigned long int)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("subu.co %1,%r4,%r5
+  __asm__ ("subu.co %1,%r4,%r5\n\
 	subu.ci %0,%r2,%r3"						\
 	   : "=r" ((unsigned long int)(sh)),				\
 	     "=&r" ((unsigned long int)(sl))				\
@@ -543,11 +543,11 @@
   } while (0)
 
 #define udiv_qrnnd(q, r, n1, n0, d) \
-  __asm__ ("or	r10,%2,0
-	or	r11,%3,0
-	divu.d	r10,r10,%4
-	mulu	%1,%4,r11
-	subu	%1,%3,%1
+  __asm__ ("or	r10,%2,0\n\
+	or	r11,%3,0\n\
+	divu.d	r10,r10,%4\n\
+	mulu	%1,%4,r11\n\
+	subu	%1,%3,%1\n\
 	or	%0,r11,0"						\
 	   : "=r" (q),							\
 	     "=&r" (r)							\
@@ -569,8 +569,8 @@
 	     "d" ((unsigned long int)(v)))
 #else
 #define umul_ppmm(w1, w0, u, v) \
-  __asm__ ("multu %2,%3
-	mflo %0
+  __asm__ ("multu %2,%3a\n\
+	mflo %0\n\
 	mfhi %1"							\
 	   : "=d" ((unsigned long int)(w0)),				\
 	     "=d" ((unsigned long int)(w1))				\
@@ -599,10 +599,10 @@
 	       "g" ((unsigned long int)(v)));				\
     __w; })
 #define udiv_qrnnd(q, r, n1, n0, d) \
-  __asm__ ("movd %2,r0
-	movd %3,r1
-	deid %4,r0
-	movd r1,%0
+  __asm__ ("movd %2,r0\n\
+	movd %3,r1\n\
+	deid %4,r0\n\
+	movd r1,%0\n\
 	movd r0,%1"							\
 	   : "=g" ((unsigned long int)(q)),				\
 	     "=g" ((unsigned long int)(r))				\
@@ -614,7 +614,7 @@
 
 #if defined (__pyr__)
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("addw	%5,%1
+  __asm__ ("addw	%5,%1\n\
 	addwc	%3,%0"							\
 	   : "=r" ((unsigned long int)(sh)),				\
 	     "=&r" ((unsigned long int)(sl))				\
@@ -623,7 +623,7 @@
 	     "%1" ((unsigned long int)(al)),				\
 	     "g" ((unsigned long int)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("subw	%5,%1
+  __asm__ ("subw	%5,%1\
 	subwb	%3,%0"							\
 	   : "=r" ((unsigned long int)(sh)),				\
 	     "=&r" ((unsigned long int)(sl))				\
@@ -647,7 +647,7 @@
 
 #if defined (__ibm032__) /* RT/ROMP */
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("a %1,%5
+  __asm__ ("a %1,%5\n\
 	ae %0,%3"							\
 	   : "=r" ((unsigned long int)(sh)),				\
 	     "=&r" ((unsigned long int)(sl))				\
@@ -656,7 +656,7 @@
 	     "%1" ((unsigned long int)(al)),				\
 	     "r" ((unsigned long int)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("s %1,%5
+  __asm__ ("s %1,%5\n\
 	se %0,%3"							\
 	   : "=r" ((unsigned long int)(sh)),				\
 	     "=&r" ((unsigned long int)(sl))				\
@@ -668,25 +668,25 @@
   do {									\
     unsigned long int __m0 = (m0), __m1 = (m1);				\
     __asm__ (								\
-       "s	r2,r2
-	mts	r10,%2
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	m	r2,%3
-	cas	%0,r2,r0
+       "s	r2,r2\n\
+	mts	r10,%2\n\
+	m	r2,%3\n\
+	m	r2,%3\n\
+	m	r2,%3\n\
+	m	r2,%3\n\
+	m	r2,%3\n\
+	m	r2,%3\n\
+	m	r2,%3\n\
+	m	r2,%3\n\
+	m	r2,%3\n\
+	m	r2,%3\n\
+	m	r2,%3\n\
+	m	r2,%3\n\
+	m	r2,%3\n\
+	m	r2,%3\n\
+	m	r2,%3\n\
+	m	r2,%3\n\
+	cas	%0,r2,r0\n\
 	mfs	r10,%1"							\
 	     : "=r" ((unsigned long int)(ph)),				\
 	       "=r" ((unsigned long int)(pl))				\
@@ -716,7 +716,7 @@
 
 #if defined (__sparc__)
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("addcc %4,%5,%1
+  __asm__ ("addcc %4,%5,%1\n\
 	addx %2,%3,%0"							\
 	   : "=r" ((unsigned long int)(sh)),				\
 	     "=&r" ((unsigned long int)(sl))				\
@@ -726,7 +726,7 @@
 	     "rI" ((unsigned long int)(bl))				\
 	   __CLOBBER_CC)
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("subcc %4,%5,%1
+  __asm__ ("subcc %4,%5,%1\n\
 	subx %2,%3,%0"							\
 	   : "=r" ((unsigned long int)(sh)),				\
 	     "=&r" ((unsigned long int)(sl))				\
@@ -757,45 +757,45 @@
 /* SPARC without integer multiplication and divide instructions.
    (i.e. at least Sun4/20,40,60,65,75,110,260,280,330,360,380,470,490) */
 #define umul_ppmm(w1, w0, u, v) \
-  __asm__ ("! Inlined umul_ppmm
-	wr	%%g0,%2,%%y	! SPARC has 0-3 delay insn after a wr
-	sra	%3,31,%%g2	! Don't move this insn
-	and	%2,%%g2,%%g2	! Don't move this insn
-	andcc	%%g0,0,%%g1	! Don't move this insn
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,%3,%%g1
-	mulscc	%%g1,0,%%g1
-	add	%%g1,%%g2,%0
+  __asm__ ("! Inlined umul_ppmm\
+	wr	%%g0,%2,%%y	! SPARC has 0-3 delay insn after a wr\n\
+	sra	%3,31,%%g2	! Don't move this insn\n\
+	and	%2,%%g2,%%g2	! Don't move this insn\n\
+	andcc	%%g0,0,%%g1	! Don't move this insn\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,%3,%%g1\n\
+	mulscc	%%g1,0,%%g1\n\
+	add	%%g1,%%g2,%0\n\
 	rd	%%y,%1"							\
 	   : "=r" ((unsigned long int)(w1)),				\
 	     "=r" ((unsigned long int)(w0))				\
@@ -806,29 +806,29 @@
 /* It's quite necessary to add this much assembler for the sparc.
    The default udiv_qrnnd (in C) is more than 10 times slower!  */
 #define udiv_qrnnd(q, r, n1, n0, d) \
-  __asm__ ("! Inlined udiv_qrnnd
-	mov	32,%%g1
-	subcc	%1,%2,%%g0
-1:	bcs	5f
-	 addxcc %0,%0,%0	! shift n1n0 and a q-bit in lsb
-	sub	%1,%2,%1	! this kills msb of n
-	addx	%1,%1,%1	! so this can't give carry
-	subcc	%%g1,1,%%g1
-2:	bne	1b
-	 subcc	%1,%2,%%g0
-	bcs	3f
-	 addxcc %0,%0,%0	! shift n1n0 and a q-bit in lsb
-	b	3f
-	 sub	%1,%2,%1	! this kills msb of n
-4:	sub	%1,%2,%1
-5:	addxcc	%1,%1,%1
-	bcc	2b
-	 subcc	%%g1,1,%%g1
-! Got carry from n.  Subtract next step to cancel this carry.
-	bne	4b
-	 addcc	%0,%0,%0	! shift n1n0 and a 0-bit in lsb
-	sub	%1,%2,%1
-3:	xnor	%0,0,%0
+  __asm__ ("! Inlined udiv_qrnnd\
+	mov	32,%%g1\n\
+	subcc	%1,%2,%%g0\n\
+1:	bcs	5f\n\
+	 addxcc %0,%0,%0	! shift n1n0 and a q-bit in lsb\n\
+	sub	%1,%2,%1	! this kills msb of n\n\
+	addx	%1,%1,%1	! so this can't give carry\n\
+	subcc	%%g1,1,%%g1\n\
+2:	bne	1b\n\
+	 subcc	%1,%2,%%g0\n\
+	bcs	3f\n\
+	 addxcc %0,%0,%0	! shift n1n0 and a q-bit in lsb\n\
+	b	3f\n\
+	 sub	%1,%2,%1	! this kills msb of n\n\
+4:	sub	%1,%2,%1\n\
+5:	addxcc	%1,%1,%1\n\
+	bcc	2b\n\
+	 subcc	%%g1,1,%%g1\n\
+! Got carry from n.  Subtract next step to cancel this carry.\n\
+	bne	4b\n\
+	 addcc	%0,%0,%0	! shift n1n0 and a 0-bit in lsb\n\
+	sub	%1,%2,%1\n\
+3:	xnor	%0,0,%0\
 	! End of inline udiv_qrnnd"					\
 	   : "=&r" ((unsigned long int)(q)),				\
 	     "=&r" ((unsigned long int)(r))				\
@@ -841,7 +841,7 @@
 
 #if defined (__vax__)
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
-  __asm__ ("addl2 %5,%1
+  __asm__ ("addl2 %5,%1\n\
 	adwc %3,%0"							\
 	   : "=g" ((unsigned long int)(sh)),				\
 	     "=&g" ((unsigned long int)(sl))				\
@@ -850,7 +850,7 @@
 	     "%1" ((unsigned long int)(al)),				\
 	     "g" ((unsigned long int)(bl)))
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
-  __asm__ ("subl2 %5,%1
+  __asm__ ("subl2 %5,%1\n\
 	sbwc %3,%0"							\
 	   : "=g" ((unsigned long int)(sh)),				\
 	     "=&g" ((unsigned long int)(sl))				\

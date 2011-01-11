--- lib-source/libgcc/libgcc1.S.orig	1995-07-12 05:17:00.000000000 +0200
+++ lib-source/libgcc/libgcc1.S	2007-06-18 12:04:45.000000000 +0200
***************
*** 16,23 ****
--- 16,33 ----
  	xdef ___extendti
  	xdef ___extendsidi2
  
+ 	xdef ___ashlti2
+ 	xdef ___ashldi2
+ 	xdef ___ashrdi2
+ 	xdef ___ashrti2
+ 	xdef ___xordi3
+ 	xdef ___xorsi3
+ 
  	xdef ___divdi3
  	xdef ___divti3
+ 	xdef ___moddi3
+ 	xdef ___modti3
+ 	xdef ___umodsi3
  	xdef ___mulpdi3
  	xdef ___muldi3
  	xdef ___multi3
***************
*** 49,54 ****
--- 59,132 ----
  	move.1	#7,p
  	rtn
  
+ ___ashlti2
+ 	; left-shift 'a' for 'c' bits
+ 	move.1	#2,p
+ 	move.14	#0,c.p
+ 	beq.b	c,0,.t1
+ .t0
+ 	sub.b	#1,c
+ 	lsl.w	#1,a
+ 	bne.b	c,0,.t0
+ .t1
+ 	move.1	#7,p
+ 	rtn
+ 
+ ___ashldi2
+ 	; left-shift 'a' for 'c' bits
+ 	move.1	#2,p
+ 	move.14	#0,c.p
+ 	beq.b	c,0,.t1
+ .t0
+ 	sub.b	#1,c
+ 	lsl.w	#1,a
+ 	bne.b	c,0,.t0
+ .t1
+ 	move.1	#8,p
+ 	move.8	#0,a.p
+ 	move.1	#7,p
+ 	rtn
+ 
+ ___ashrdi2
+ 	; right-shift 'a' for 'c' bits
+ 	move.1	#8,p
+ 	move.8	#0,a.p
+ 	
+ ___ashrti2
+ 	; right-shift 'a' for 'c' bits
+ 	move.1	#2,p
+ 	move.14	#0,c.p
+ 	beq.b	c,0,.t1
+ .t0
+ 	sub.b	#1,c
+ 	lsr.w	#1,a
+ 	bne.b	c,0,.t0
+ .t1
+ 	move.1	#7,p
+ 	rtn
+ 
+ ___xordi3
+ 	; c = b ^ r0
+ 	move.w	r0,a
+ 	and.w	b,a
+ 	not.w	a
+ 	and.w	a,b
+ 	move.w	r0,c
+ 	and.w	a,c
+ 	or.w	b,c
+ 	rtn
+ 
+ ___xorsi3
+ 	; c = b ^ r0
+ 	move.a	r0,a
+ 	and.a	b,a
+ 	not.a	a
+ 	and.a	a,b
+ 	move.a	r0,c
+ 	and.a	a,c
+ 	or.a	b,c
+ 	rtn
+ 
  ___divdi3
  	; wp-mode c = b/r0
  
***************
*** 68,73 ****
--- 146,182 ----
  	move.1 #7,p
  	rtn
  
+ ___moddi3
+ 	; wp-mode c = b%r0
+ 	move.1 	#7,p
+ 	move.w	b,a
+ 	move.8	#0,a.p
+ 	move.w	a,b
+ 	move.w	r0,c
+ 	move.8	#0,c.p
+ 	move.w	c,r0
+ 
+ ___modti3
+ 	; word-mode C = B % R0
+ 	move.w	b,a	; a = parm 1
+ 	move.w	r0,c	; c = parm 2
+ 	jsr 	HXSDIV	; word-mode [[ a = c = a/c , b = a%c ]]
+ 	move.w	b,c
+ 	move.1 #7,p
+ 	rtn
+ 
+ ___umodsi3
+ 	; wp-mode c = b%r0
+ 	move.1 	#2,p
+ 	move.w	b,a	; a = parm 1
+ 	move.14	#0,a.p
+ 	move.w	r0,c	; c = parm 2
+ 	move.14	#0,c.p
+ 	jsr 	$HXSDIV	; word-mode [[ a = c = a/c , b = a%c ]]
+ 	move.w	b,c	; result in c
+ 	move.1 #7,p
+ 	rtn
+ 
  ___mulpdi3
  	move.a	r0,a
  	;;

--- /ports/devel/sdl12/work/SDL-1.2.7/src/audio/SDL_mixer_MMX.c	Sat Nov  9 07:13:28 2002
+++ SDL_mixer_MMX.c	Sun May 16 19:19:47 2004
@@ -15,13 +15,11 @@
 {
     __asm__ __volatile__ (
 
-"	movl %0,%%edi\n"	// edi = dst
-"	movl %1,%%esi\n"	// esi = src
 "	movl %3,%%eax\n"	// eax = volume
 
-"	movl %2,%%ebx\n"	// ebx = size
+"	movl %2,%%edx\n"	// edx = size
 
-"	shrl $4,%%ebx\n"	// process 16 bytes per iteration = 8 samples
+"	shrl $4,%%edx\n"	// process 16 bytes per iteration = 8 samples
 
 "	jz .endS16\n"
 
@@ -39,14 +37,14 @@
 ".align 16\n"
 "	.mixloopS16:\n"
 
-"	movq (%%esi),%%mm1\n" // mm1 = a|b|c|d
+"	movq (%1),%%mm1\n" // mm1 = a|b|c|d
 
 "	movq %%mm1,%%mm2\n" // mm2 = a|b|c|d
 
-"	movq 8(%%esi),%%mm4\n" // mm4 = e|f|g|h
+"	movq 8(%1),%%mm4\n" // mm4 = e|f|g|h
 
 	// pré charger le buffer dst dans mm7
-"	movq (%%edi),%%mm7\n" // mm7 = dst[0]"
+"	movq (%0),%%mm7\n" // mm7 = dst[0]"
 
 	// multiplier par le volume
 "	pmullw %%mm0,%%mm1\n" // mm1 = l(a*v)|l(b*v)|l(c*v)|l(d*v)
@@ -69,11 +67,11 @@
 "	punpcklwd %%mm5,%%mm6\n" // mm6 = g*v|h*v
 
 	// pré charger le buffer dst dans mm5
-"	movq 8(%%edi),%%mm5\n" // mm5 = dst[1]
+"	movq 8(%0),%%mm5\n" // mm5 = dst[1]
 
 	// diviser par 128
 "	psrad $7,%%mm1\n" // mm1 = a*v/128|b*v/128 , 128 = SDL_MIX_MAXVOLUME
-"	addl $16,%%esi\n"
+"	add $16,%1\n"
 
 "	psrad $7,%%mm3\n" // mm3 = c*v/128|d*v/128
 
@@ -87,15 +85,15 @@
 
 	// mm4 = le sample avec le volume modifié
 "	packssdw %%mm4,%%mm6\n" // mm6 = s(e*v|f*v|g*v|h*v)
-"	movq %%mm3,(%%edi)\n"
+"	movq %%mm3,(%0)\n"
 
 "	paddsw %%mm5,%%mm6\n" // mm6 = adjust_volume(src)+dst
 
-"	movq %%mm6,8(%%edi)\n"
+"	movq %%mm6,8(%0)\n"
 
-"	addl $16,%%edi\n"
+"	add $16,%0\n"
 
-"	dec %%ebx\n"
+"	dec %%edx\n"
 
 "	jnz .mixloopS16\n"
 
@@ -103,9 +101,9 @@
 
 ".endS16:\n"
 	 :
-	 : "m" (dst), "m"(src),"m"(size),
+	 : "r" (dst), "r"(src),"m"(size),
 	 "m"(volume)
-	 : "eax","ebx", "esi", "edi","memory"
+	 : "eax","edx","memory"
 	 );
 }
 
@@ -119,11 +117,9 @@
 {
     __asm__ __volatile__ (
 
-"	movl %0,%%edi\n"	// edi = dst
-"	movl %1,%%esi\n"	// esi = src
 "	movl %3,%%eax\n"	// eax = volume
 
-"	movd %%ebx,%%mm0\n"
+"	movd %%edx,%%mm0\n"
 "	movq %%mm0,%%mm1\n"
 "	psllq $16,%%mm0\n"
 "	por %%mm1,%%mm0\n"
@@ -132,17 +128,17 @@
 "	psllq $16,%%mm0\n"
 "	por %%mm1,%%mm0\n"
 
-"	movl %2,%%ebx\n"	// ebx = size
-"	shr $3,%%ebx\n"	// process 8 bytes per iteration = 8 samples
+"	movl %2,%%edx\n"	// edx = size
+"	shr $3,%%edx\n"	// process 8 bytes per iteration = 8 samples
 
-"	cmp $0,%%ebx\n"
+"	cmp $0,%%edx\n"
 "	je .endS8\n"
 
 ".align 16\n"
 "	.mixloopS8:\n"
 
 "	pxor %%mm2,%%mm2\n"		// mm2 = 0
-"	movq (%%esi),%%mm1\n"	// mm1 = a|b|c|d|e|f|g|h
+"	movq (%1),%%mm1\n"	// mm1 = a|b|c|d|e|f|g|h
 
 "	movq %%mm1,%%mm3\n" 	// mm3 = a|b|c|d|e|f|g|h
 
@@ -152,10 +148,10 @@
 "	punpckhbw %%mm2,%%mm1\n"	// mm1 = 0|a|0|b|0|c|0|d
 
 "	punpcklbw %%mm2,%%mm3\n"	// mm3 = 0|e|0|f|0|g|0|h
-"	movq (%%edi),%%mm2\n"	// mm2 = destination
+"	movq (%0),%%mm2\n"	// mm2 = destination
 
 "	pmullw %%mm0,%%mm1\n"	// mm1 = v*a|v*b|v*c|v*d
-"	addl $8,%%esi\n"
+"	add $8,%1\n"
 
 "	pmullw %%mm0,%%mm3\n"	// mm3 = v*e|v*f|v*g|v*h
 "	psraw $7,%%mm1\n"		// mm1 = v*a/128|v*b/128|v*c/128|v*d/128 
@@ -166,19 +162,19 @@
 
 "	paddsb %%mm2,%%mm3\n"	// add to destination buffer
 
-"	movq %%mm3,(%%edi)\n"	// store back to ram
-"	addl $8,%%edi\n"
+"	movq %%mm3,(%0)\n"	// store back to ram
+"	add $8,%0\n"
 
-"	dec %%ebx\n"
+"	dec %%edx\n"
 
 "	jnz .mixloopS8\n"
 
 ".endS8:\n"
 "	emms\n"
 	 :
-	 : "m" (dst), "m"(src),"m"(size),
+	 : "r" (dst), "r"(src),"m"(size),
 	 "m"(volume)
-	 : "eax","ebx", "esi", "edi","memory"
+	 : "eax","edx","memory"
 	 );
 }
 #endif

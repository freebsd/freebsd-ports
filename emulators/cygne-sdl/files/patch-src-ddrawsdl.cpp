--- ddrawsdl.cpp.orig	Tue Mar 26 09:02:25 2002
+++ ddrawsdl.cpp	Thu May  4 18:18:12 2006
@@ -174,67 +174,67 @@
 {
 	switch(fBlitterMode) {
 		case 1:
-			__asm__ __volatile__(".align 32
-							 cld
-							 rep
-							 movsw"
+			__asm__ __volatile__(".align 32\n\t"
+							"cld\n\t"
+							"rep\n\t"
+							"movsw"
 							 :
 							 :"S"(dx_buffer), "D"(g_pDDSPrimary->pixels), "c"((g_pDDSPrimary->h * g_pDDSPrimary->pitch)>>1));
 		break;
 		case 2:
-			__asm__ __volatile__("pusha
-								 xorl %%eax, %%eax
-								 movl $448, %%ebx 
-								 emms
-								 sum:
-								 movq (%0, %%eax, 1), %%mm0
-								 movq %%mm0, %%mm1
-								 punpcklwd %%mm0, %%mm0
-								 addl $8, %%eax
-								 punpckhwd %%mm1,%%mm1
-								 movq %%mm0, -16(%1, %%eax, 2)
-								 cmpl %%ebx, %%eax
-								 
-								 movq %%mm1, -8(%1, %%eax, 2)
-								 jnz sum
-								 xorl %%eax, %%eax
-								 
-								 addl %2, %0
-								 decl %%edx
-								 
-								 leal (%1, %2, 4), %1
-								 jnz sum
-								 emms
-								 popa"
+			__asm__ __volatile__("pusha\n\t"
+								"xorl %%eax, %%eax\n\t"
+								"movl $448, %%ebx\n\t"
+								"emms\n\t"
+								"sum:\n\t"
+								"movq (%0, %%eax, 1), %%mm0\n\t"
+								"movq %%mm0, %%mm1\n\t"
+								"punpcklwd %%mm0, %%mm0\n\t"
+								"addl $8, %%eax\n\t"
+								"punpckhwd %%mm1,%%mm1\n\t"
+								"movq %%mm0, -16(%1, %%eax, 2)\n\t"
+								"cmpl %%ebx, %%eax\n\t"
+								 
+								"movq %%mm1, -8(%1, %%eax, 2)\n\t"
+								"jnz sum\n\t"
+								"xorl %%eax, %%eax\n\t"
+								 
+								"addl %2, %0\n\t"
+								"decl %%edx\n\t"
+								 
+								"leal (%1, %2, 4), %1\n\t"
+								"jnz sum\n\t"
+								"emms\n\t"
+								"popa"
 			:
 			: "S"(dx_buffer), "D"(g_pDDSPrimary->pixels), "c"(g_pDDSPrimary->pitch>>1), "d"(144));
 		break;
 		
 		case 3:
-			__asm__ __volatile__("pusha
-								 xorl %%eax, %%eax
-								 movl $896, %%ebx 
-								 emms
-								 sum3:
-								 movq (%0, %%eax, 1), %%mm0
-								 movq %%mm0, %%mm1
-								 punpcklwd %%mm0, %%mm0
-								 addl $8, %%eax
-								 punpckhwd %%mm1,%%mm1
-								 movq %%mm0, -16(%1, %%eax, 2)
-								 cmpl %%ebx, %%eax
-								 
-								 movq %%mm1, -8(%1, %%eax, 2)
-								 jnz sum3
-								 xorl %%eax, %%eax
-								 
-								 addl %2, %0
-								 decl %%edx
-								 
-								 leal (%1, %2, 4), %1
-								 jnz sum3
-								 emms
-								 popa"
+			__asm__ __volatile__("pusha\n\t"
+								"xorl %%eax, %%eax\n\t"
+								"movl $896, %%ebx\n\t"
+								"emms\n"
+								"sum3:\n\t"
+								"movq (%0, %%eax, 1), %%mm0\n\t"
+								"movq %%mm0, %%mm1\n\t"
+								"punpcklwd %%mm0, %%mm0\n\t"
+								"addl $8, %%eax\n\t"
+								"punpckhwd %%mm1,%%mm1\n\t"
+								"movq %%mm0, -16(%1, %%eax, 2)\n\t"
+								"cmpl %%ebx, %%eax\n\t"
+								"\n\t"
+								"movq %%mm1, -8(%1, %%eax, 2)\n\t"
+								"jnz sum3\n\t"
+								"xorl %%eax, %%eax\n\t"
+								"\n\t"
+								"addl %2, %0\n\t"
+								"decl %%edx\n\t"
+								"\n\t"
+								"leal (%1, %2, 4), %1\n\t"
+								"jnz sum3\n\t"
+								"emms\n\t"
+								"popa"
 			:
 			: "S"(dx_buffer), "D"(g_pDDSPrimary->pixels), "c"(g_pDDSPrimary->pitch>>1), "d"(144));
 		break;
@@ -418,66 +418,66 @@
 {
 	switch(fBlitterMode) {
 		case 1:
-			__asm__ __volatile__(".align 32
-							 cld
-							 rep
-							 movsw"
+			__asm__ __volatile__(".align 32\n\t"
+							"cld\n\t"
+							"rep\n\t"
+							"movsw"
 							 :
 							 :"S"(dx_buffer), "D"(g_pDDSPrimary->pixels), "c"((g_pDDSPrimary->h * g_pDDSPrimary->pitch)>>1));
 		break;
 		case 2: // double scanlines
-			__asm__ __volatile__("pusha
-								 xorl %%eax, %%eax
-								 movl $288, %%ebx 
-								 emms
-								 sumb:
-								 movq (%0, %%eax, 1), %%mm0
-								 movq %%mm0, %%mm1
-								 punpcklwd %%mm0, %%mm0
-								 addl $8, %%eax
-								 punpckhwd %%mm1,%%mm1
-								 movq %%mm0, -16(%1, %%eax, 2)
-								 cmpl %%ebx, %%eax
-								 
-								 movq %%mm1, -8(%1, %%eax, 2)
-								 jnz sumb
-								 xorl %%eax, %%eax
-								 
-								 addl %2, %0
-								 decl %%edx
-								 
-								 leal (%1, %2, 4), %1
-								 jnz sumb
-								 emms
-								 popa"
+			__asm__ __volatile__("pusha\n\t"
+								"xorl %%eax, %%eax\n\t"
+								"movl $288, %%ebx\n\t"
+								"emms\n"
+								"sumb:\n\t"
+								"movq (%0, %%eax, 1), %%mm0\n\t"
+								"movq %%mm0, %%mm1\n\t"
+								"punpcklwd %%mm0, %%mm0\n\t"
+								"addl $8, %%eax\n\t"
+								"punpckhwd %%mm1,%%mm1\n\t"
+								"movq %%mm0, -16(%1, %%eax, 2)\n\t"
+								"cmpl %%ebx, %%eax\n\t"
+								"\n\t"
+								"movq %%mm1, -8(%1, %%eax, 2)\n\t"
+								"jnz sumb\n\t"
+								"xorl %%eax, %%eax\n\t"
+								"\n\t"
+								"addl %2, %0\n\t"
+								"decl %%edx\n\t"
+								"\n\t"
+								"leal (%1, %2, 4), %1\n\t"
+								"jnz sumb\n\t"
+								"emms\n\t"
+								"popa"
 			:
 			: "S"(dx_buffer), "D"(g_pDDSPrimary->pixels), "c"(g_pDDSPrimary->pitch>>1), "d"(224));
 		break;
 		case 3: // double stretch mode
-			__asm__ __volatile__("pusha
-								 xorl %%eax, %%eax
-								 movl $576, %%ebx 
-								 emms
-								 sumc:
-								 movq (%0, %%eax, 1), %%mm0
-								 movq %%mm0, %%mm1
-								 punpcklwd %%mm0, %%mm0
-								 addl $8, %%eax
-								 punpckhwd %%mm1,%%mm1
-								 movq %%mm0, -16(%1, %%eax, 2)
-								 cmpl %%ebx, %%eax
-								 
-								 movq %%mm1, -8(%1, %%eax, 2)
-								 jnz sumc
-								 xorl %%eax, %%eax
-								 
-								 addl %2, %0
-								 decl %%edx
-								 
-								 leal (%1, %2, 4), %1
-								 jnz sumc
-								 emms
-								 popa"
+			__asm__ __volatile__("pusha\n\t"
+								"xorl %%eax, %%eax\n\t"
+								"movl $576, %%ebx\n\t"
+								"emms\n"
+								"sumc:\n\t"
+								"movq (%0, %%eax, 1), %%mm0\n\t"
+								"movq %%mm0, %%mm1\n\t"
+								"punpcklwd %%mm0, %%mm0\n\t"
+								"addl $8, %%eax\n\t"
+								"punpckhwd %%mm1,%%mm1\n\t"
+								"movq %%mm0, -16(%1, %%eax, 2)\n\t"
+								"cmpl %%ebx, %%eax\n\t"
+								"\n\t"
+								"movq %%mm1, -8(%1, %%eax, 2)\n\t"
+								"jnz sumc\n\t"
+								"xorl %%eax, %%eax\n\t"
+								"\n\t"
+								"addl %2, %0\n\t"
+								"decl %%edx\n\t"
+								"\n\t"
+								"leal (%1, %2, 4), %1\n\t"
+								"jnz sumc\n\t"
+								"emms\n\t"
+								"popa"
 			:
 			: "S"(dx_buffer), "D"(g_pDDSPrimary->pixels), "c"(g_pDDSPrimary->pitch>>1), "d"(224));
 		break;

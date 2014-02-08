--- ddrawsdl.cpp.orig	Tue Mar 26 09:02:25 2002
+++ ddrawsdl.cpp	Thu May  4 18:18:12 2006
@@ -12,6 +12,7 @@
 */
 
 #include <SDL.h>
+#include <assert.h>
 #include "globals.h"
 #include "gfx.h"
 
@@ -174,69 +175,83 @@ void UpdateFrame_h()
 {
 	switch(fBlitterMode) {
 		case 1:
-			__asm__ __volatile__(".align 32
-							 cld
-							 rep
+#if defined(__i386__) || defined(__amd64__) || defined(__x86_64__)
+			__asm__ __volatile__(".align 32\n\
+							 cld\n\
+							 rep\n\
 							 movsw"
 							 :
 							 :"S"(dx_buffer), "D"(g_pDDSPrimary->pixels), "c"((g_pDDSPrimary->h * g_pDDSPrimary->pitch)>>1));
+#else
+			memcpy(g_pDDSPrimary->pixels, dx_buffer, g_pDDSPrimary->h * g_pDDSPrimary->pitch);
+#endif
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
+#if defined(__i386__)
+			__asm__ __volatile__("pusha\n\
+								 xorl %%eax, %%eax\n\
+								 movl $448, %%ebx \n\
+								 emms\n\
+								 sum:\n\
+								 movq (%0, %%eax, 1), %%mm0\n\
+								 movq %%mm0, %%mm1\n\
+								 punpcklwd %%mm0, %%mm0\n\
+								 addl $8, %%eax\n\
+								 punpckhwd %%mm1,%%mm1\n\
+								 movq %%mm0, -16(%1, %%eax, 2)\n\
+								 cmpl %%ebx, %%eax\n\
+								 \n\
+								 movq %%mm1, -8(%1, %%eax, 2)\n\
+								 jnz sum\n\
+								 xorl %%eax, %%eax\n\
+								 \n\
+								 addl %2, %0\n\
+								 decl %%edx\n\
+								 \n\
+								 leal (%1, %2, 4), %1\n\
+								 jnz sum\n\
+								 emms\n\
 								 popa"
 			:
 			: "S"(dx_buffer), "D"(g_pDDSPrimary->pixels), "c"(g_pDDSPrimary->pitch>>1), "d"(144));
+#else
+			/* If you put real code here, enable the corresponding option in main() */
+			assert(0);
+#endif
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
+#if defined(__i386__)
+			__asm__ __volatile__("pusha\n\
+								 xorl %%eax, %%eax\n\
+								 movl $896, %%ebx \n\
+								 emms\n\
+								 sum3:\n\
+								 movq (%0, %%eax, 1), %%mm0\n\
+								 movq %%mm0, %%mm1\n\
+								 punpcklwd %%mm0, %%mm0\n\
+								 addl $8, %%eax\n\
+								 punpckhwd %%mm1,%%mm1\n\
+								 movq %%mm0, -16(%1, %%eax, 2)\n\
+								 cmpl %%ebx, %%eax\n\
+								 \n\
+								 movq %%mm1, -8(%1, %%eax, 2)\n\
+								 jnz sum3\n\
+								 xorl %%eax, %%eax\n\
+								 \n\
+								 addl %2, %0\n\
+								 decl %%edx\n\
+								 \n\
+								 leal (%1, %2, 4), %1\n\
+								 jnz sum3\n\
+								 emms\n\
 								 popa"
 			:
 			: "S"(dx_buffer), "D"(g_pDDSPrimary->pixels), "c"(g_pDDSPrimary->pitch>>1), "d"(144));
+#else
+			/* If you put real code here, enable the corresponding option in main() */
+			assert(0);
+#endif
 		break;
 	}
 	//Niels(adjust to suit) use the asm below, or use standard memcpy/fast_memcpy etc, updateframe_v is not implemented
@@ -418,68 +433,82 @@ void UpdateFrame_v()
 {
 	switch(fBlitterMode) {
 		case 1:
-			__asm__ __volatile__(".align 32
-							 cld
-							 rep
+#if defined(__i386__) || defined(__amd64__) || defined(__x86_64__)
+			__asm__ __volatile__(".align 32\n\
+							 cld\n\
+							 rep\n\
 							 movsw"
 							 :
 							 :"S"(dx_buffer), "D"(g_pDDSPrimary->pixels), "c"((g_pDDSPrimary->h * g_pDDSPrimary->pitch)>>1));
+#else
+			memcpy(g_pDDSPrimary->pixels, dx_buffer, g_pDDSPrimary->h * g_pDDSPrimary->pitch);
+#endif
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
+#if defined(__i386__)
+			__asm__ __volatile__("pusha\n\
+								 xorl %%eax, %%eax\n\
+								 movl $288, %%ebx \n\
+								 emms\n\
+								 sumb:\n\
+								 movq (%0, %%eax, 1), %%mm0\n\
+								 movq %%mm0, %%mm1\n\
+								 punpcklwd %%mm0, %%mm0\n\
+								 addl $8, %%eax\n\
+								 punpckhwd %%mm1,%%mm1\n\
+								 movq %%mm0, -16(%1, %%eax, 2)\n\
+								 cmpl %%ebx, %%eax\n\
+								 \n\
+								 movq %%mm1, -8(%1, %%eax, 2)\n\
+								 jnz sumb\n\
+								 xorl %%eax, %%eax\n\
+								 \n\
+								 addl %2, %0\n\
+								 decl %%edx\n\
+								 \n\
+								 leal (%1, %2, 4), %1\n\
+								 jnz sumb\n\
+								 emms\n\
 								 popa"
 			:
 			: "S"(dx_buffer), "D"(g_pDDSPrimary->pixels), "c"(g_pDDSPrimary->pitch>>1), "d"(224));
+#else
+			/* If you put real code here, enable the corresponding option in main() */
+			assert(0);
+#endif
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
+#if defined(__i386__)
+			__asm__ __volatile__("pusha\n\
+								 xorl %%eax, %%eax\n\
+								 movl $576, %%ebx \n\
+								 emms\n\
+								 sumc:\n\
+								 movq (%0, %%eax, 1), %%mm0\n\
+								 movq %%mm0, %%mm1\n\
+								 punpcklwd %%mm0, %%mm0\n\
+								 addl $8, %%eax\n\
+								 punpckhwd %%mm1,%%mm1\n\
+								 movq %%mm0, -16(%1, %%eax, 2)\n\
+								 cmpl %%ebx, %%eax\n\
+								 \n\
+								 movq %%mm1, -8(%1, %%eax, 2)\n\
+								 jnz sumc\n\
+								 xorl %%eax, %%eax\n\
+								 \n\
+								 addl %2, %0\n\
+								 decl %%edx\n\
+								 \n\
+								 leal (%1, %2, 4), %1\n\
+								 jnz sumc\n\
+								 emms\n\
 								 popa"
 			:
 			: "S"(dx_buffer), "D"(g_pDDSPrimary->pixels), "c"(g_pDDSPrimary->pitch>>1), "d"(224));
+#else
+			/* If you put real code here, enable the corresponding option in main() */
+			assert(0);
+#endif
 		break;
 	}
 	SDL_Flip(g_pDDSPrimary);

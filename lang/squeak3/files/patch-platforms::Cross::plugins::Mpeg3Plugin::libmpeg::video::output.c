--- platforms/Cross/plugins/Mpeg3Plugin/libmpeg/video/output.c.orig	Sun Aug 31 20:43:57 2003
+++ platforms/Cross/plugins/Mpeg3Plugin/libmpeg/video/output.c	Sun Aug 31 20:45:36 2003
@@ -261,38 +261,38 @@
 		unsigned long v, 
 		unsigned long *output)
 {
-asm("
-/* Output will be 0x00rrggbb with the 00 trailing so this can also be used */
-/* for bgr24. */
-	movd (%0), %%mm0;          /* Load y   0x00000000000000yy */
-	movd (%1), %%mm1;          /* Load u    0x00000000000000cr */
-	movq %%mm0, %%mm3;         /* Copy y to temp */
-	psllq $16, %%mm1;          /* Shift u   0x0000000000cr0000 */
-	movd (%2), %%mm2;          /* Load v    0x00000000000000cb */
-	psllq $16, %%mm3;          /* Shift y */
-	movq %%mm1, %%mm4;         /* Copy u to temp */
-	por %%mm3, %%mm0;          /* Overlay new y byte 0x0000000000yy00yy */
-	psllq $16, %%mm4;          /* Shift u */
-	movq %%mm2, %%mm5;         /* Copy v to temp */
-	psllq $16, %%mm3;          /* Shift y  */
-	por %%mm4, %%mm1;          /* Overlay new u byte 0x000000cr00cr0000 */
-	psllq $16, %%mm5;          /* Shift v  */
-	por %%mm3, %%mm0;          /* Overlay new y byte 0x000000yy00yy00yy */
-	por %%mm5, %%mm2;          /* Overlay new v byte 0x0000000000cb00cb */
-
-/* mm0: 0x000000yy00yy00yy mm1: 0x000000uu00uu0000 mm2: 0x0000000000vv00vv */
- 	psubw _mpeg3_MMX_U_80, %%mm1;    /* Subtract 128 from u 0x000000uu00uu0000 */
- 	pmullw _mpeg3_MMX_U_COEF, %%mm1; /* Multiply u coeffs 0x0000uuuuuuuu0000 */
- 	psllw $6, %%mm0;                /* Shift y coeffs 0x0000yyy0yyy0yyy0 */
- 	psubw _mpeg3_MMX_V_80, %%mm2;    /* Subtract 128 from v 0x0000000000cb00cb */
- 	pmullw _mpeg3_MMX_V_COEF, %%mm2; /* Multiply v coeffs 0x0000crcrcrcrcrcr */
-
-/* mm0: 0x000000yy00yy00yy mm1: 0x0000uuuuuuuu0000 mm2: 0x00000000vvvvvvvv */
-	paddsw %%mm1, %%mm0;        /* Add u to result */
-	paddsw %%mm2, %%mm0;        /* Add v to result 0x0000rrrrggggbbbb */
-	psraw $6, %%mm0;           /* Demote precision */
-	packuswb %%mm0, %%mm0;     /* Pack into ARGB 0x0000000000rrggbb */
-	movd %%mm0, (%3);          /* Store output */
+asm(" \
+/* Output will be 0x00rrggbb with the 00 trailing so this can also be used */ \
+/* for bgr24. */ \
+	movd (%0), %%mm0;          /* Load y   0x00000000000000yy */ \
+	movd (%1), %%mm1;          /* Load u    0x00000000000000cr */\
+	movq %%mm0, %%mm3;         /* Copy y to temp */\
+	psllq $16, %%mm1;          /* Shift u   0x0000000000cr0000 */\
+	movd (%2), %%mm2;          /* Load v    0x00000000000000cb */\
+	psllq $16, %%mm3;          /* Shift y */\
+	movq %%mm1, %%mm4;         /* Copy u to temp */\
+	por %%mm3, %%mm0;          /* Overlay new y byte 0x0000000000yy00yy */\
+	psllq $16, %%mm4;          /* Shift u */\
+	movq %%mm2, %%mm5;         /* Copy v to temp */\
+	psllq $16, %%mm3;          /* Shift y  */\
+	por %%mm4, %%mm1;          /* Overlay new u byte 0x000000cr00cr0000 */\
+	psllq $16, %%mm5;          /* Shift v  */\
+	por %%mm3, %%mm0;          /* Overlay new y byte 0x000000yy00yy00yy */\
+	por %%mm5, %%mm2;          /* Overlay new v byte 0x0000000000cb00cb */\
+\
+/* mm0: 0x000000yy00yy00yy mm1: 0x000000uu00uu0000 mm2: 0x0000000000vv00vv */\
+ 	psubw _mpeg3_MMX_U_80, %%mm1;    /* Subtract 128 from u 0x000000uu00uu0000 */\
+ 	pmullw _mpeg3_MMX_U_COEF, %%mm1; /* Multiply u coeffs 0x0000uuuuuuuu0000 */\
+ 	psllw $6, %%mm0;                /* Shift y coeffs 0x0000yyy0yyy0yyy0 */\
+ 	psubw _mpeg3_MMX_V_80, %%mm2;    /* Subtract 128 from v 0x0000000000cb00cb */\
+ 	pmullw _mpeg3_MMX_V_COEF, %%mm2; /* Multiply v coeffs 0x0000crcrcrcrcrcr */\
+\
+/* mm0: 0x000000yy00yy00yy mm1: 0x0000uuuuuuuu0000 mm2: 0x00000000vvvvvvvv */\
+	paddsw %%mm1, %%mm0;        /* Add u to result */\
+	paddsw %%mm2, %%mm0;        /* Add v to result 0x0000rrrrggggbbbb */\
+	psraw $6, %%mm0;           /* Demote precision */\
+	packuswb %%mm0, %%mm0;     /* Pack into ARGB 0x0000000000rrggbb */\
+	movd %%mm0, (%3);          /* Store output */\
 	"
 :
 : "r" (&y), "r" (&u), "r" (&v), "r" (output));
@@ -303,39 +303,39 @@
 		unsigned long v, 
 		unsigned long *output)
 {
-asm("
-/* Output will be 0x00rrggbb with the 00 trailing so this can also be used */
-/* for bgr24. */
-	movd (%0), %%mm0;          /* Load y   0x00000000000000yy */
-	psubsw _mpeg3_MMX_601_Y_DIFF, %%mm0;      /* Subtract 16 from y */
-	movd (%1), %%mm1;          /* Load u    0x00000000000000cr */
-	movq %%mm0, %%mm3;         /* Copy y to temp */
-	psllq $16, %%mm1;          /* Shift u   0x0000000000cr0000 */
-	movd (%2), %%mm2;          /* Load v    0x00000000000000cb */
-	psllq $16, %%mm3;          /* Shift y */
-	movq %%mm1, %%mm4;         /* Copy u to temp */
-	por %%mm3, %%mm0;          /* Overlay new y byte 0x0000000000yy00yy */
-	psllq $16, %%mm4;          /* Shift u */
-	movq %%mm2, %%mm5;         /* Copy v to temp */
-	psllq $16, %%mm3;          /* Shift y  */
-	por %%mm4, %%mm1;          /* Overlay new u byte 0x000000cr00cr0000 */
-	psllq $16, %%mm5;          /* Shift v  */
-	por %%mm3, %%mm0;          /* Overlay new y byte 0x000000yy00yy00yy */
-	por %%mm5, %%mm2;          /* Overlay new v byte 0x0000000000cb00cb */
-
-/* mm0: 0x000000yy00yy00yy mm1: 0x000000uu00uu0000 mm2: 0x0000000000vv00vv */
-	pmullw _mpeg3_MMX_601_Y_COEF, %%mm0; /* Scale and shift y coeffs */
-	psubw _mpeg3_MMX_U_80, %%mm1;     /* Subtract 128 from u 0x000000uu00uu0000 */
- 	pmullw _mpeg3_MMX_U_COEF, %%mm1;  /* Multiply u coeffs 0x0000uuuuuuuu0000 */
-	psubw _mpeg3_MMX_V_80, %%mm2;     /* Subtract 128 from v 0x0000000000cb00cb */
- 	pmullw _mpeg3_MMX_V_COEF, %%mm2;  /* Multiply v coeffs 0x0000crcrcrcrcrcr */
-
-/* mm0: 0x000000yy00yy00yy mm1: 0x0000uuuuuuuu0000 mm2: 0x00000000vvvvvvvv */
-	paddsw %%mm1, %%mm0;        /* Add u to result */
-	paddsw %%mm2, %%mm0;        /* Add v to result 0x0000rrrrggggbbbb */
-	psraw $6, %%mm0;           /* Demote precision */
-	packuswb %%mm0, %%mm0;     /* Pack into ARGB 0x0000000000rrggbb */
-	movd %%mm0, (%3);          /* Store output */
+asm("\
+/* Output will be 0x00rrggbb with the 00 trailing so this can also be used */\
+/* for bgr24. */\
+	movd (%0), %%mm0;          /* Load y   0x00000000000000yy */\
+	psubsw _mpeg3_MMX_601_Y_DIFF, %%mm0;      /* Subtract 16 from y */\
+	movd (%1), %%mm1;          /* Load u    0x00000000000000cr */\
+	movq %%mm0, %%mm3;         /* Copy y to temp */\
+	psllq $16, %%mm1;          /* Shift u   0x0000000000cr0000 */\
+	movd (%2), %%mm2;          /* Load v    0x00000000000000cb */\
+	psllq $16, %%mm3;          /* Shift y */\
+	movq %%mm1, %%mm4;         /* Copy u to temp */\
+	por %%mm3, %%mm0;          /* Overlay new y byte 0x0000000000yy00yy */\
+	psllq $16, %%mm4;          /* Shift u */\
+	movq %%mm2, %%mm5;         /* Copy v to temp */\
+	psllq $16, %%mm3;          /* Shift y  */\
+	por %%mm4, %%mm1;          /* Overlay new u byte 0x000000cr00cr0000 */\
+	psllq $16, %%mm5;          /* Shift v  */\
+	por %%mm3, %%mm0;          /* Overlay new y byte 0x000000yy00yy00yy */\
+	por %%mm5, %%mm2;          /* Overlay new v byte 0x0000000000cb00cb */\
+\
+/* mm0: 0x000000yy00yy00yy mm1: 0x000000uu00uu0000 mm2: 0x0000000000vv00vv */\
+	pmullw _mpeg3_MMX_601_Y_COEF, %%mm0; /* Scale and shift y coeffs */\
+	psubw _mpeg3_MMX_U_80, %%mm1;     /* Subtract 128 from u 0x000000uu00uu0000 */\
+ 	pmullw _mpeg3_MMX_U_COEF, %%mm1;  /* Multiply u coeffs 0x0000uuuuuuuu0000 */\
+	psubw _mpeg3_MMX_V_80, %%mm2;     /* Subtract 128 from v 0x0000000000cb00cb */\
+ 	pmullw _mpeg3_MMX_V_COEF, %%mm2;  /* Multiply v coeffs 0x0000crcrcrcrcrcr */\
+\
+/* mm0: 0x000000yy00yy00yy mm1: 0x0000uuuuuuuu0000 mm2: 0x00000000vvvvvvvv */\
+	paddsw %%mm1, %%mm0;        /* Add u to result */\
+	paddsw %%mm2, %%mm0;        /* Add v to result 0x0000rrrrggggbbbb */\
+	psraw $6, %%mm0;           /* Demote precision */\
+	packuswb %%mm0, %%mm0;     /* Pack into ARGB 0x0000000000rrggbb */\
+	movd %%mm0, (%3);          /* Store output */\
 	"
 :
 : "r" (&y), "r" (&u), "r" (&v), "r" (output));
@@ -351,38 +351,38 @@
 		unsigned long v, 
 		unsigned long *output)
 {
-asm("
-/* Output will be 0x00bbggrr with the 00 trailing so this can also be used */
-/* for rgb24. */
-	movd (%0), %%mm0;          /* Load y   0x00000000000000yy */
-	movd (%1), %%mm1;          /* Load v    0x00000000000000vv */
-	movq %%mm0, %%mm3;         /* Copy y to temp */
-	psllq $16, %%mm1;          /* Shift v   0x0000000000vv0000 */
-	movd (%2), %%mm2;          /* Load u    0x00000000000000uu */
-	psllq $16, %%mm3;          /* Shift y */
-	movq %%mm1, %%mm4;         /* Copy v to temp */
-	por %%mm3, %%mm0;          /* Overlay new y byte 0x0000000000yy00yy */
-	psllq $16, %%mm4;          /* Shift v */
-	movq %%mm2, %%mm5;         /* Copy u to temp */
-	psllq $16, %%mm3;          /* Shift y  */
-	por %%mm4, %%mm1;          /* Overlay new v byte 0x000000vv00vv0000 */
-	psllq $16, %%mm5;          /* Shift u  */
-	por %%mm3, %%mm0;          /* Overlay new y byte 0x000000yy00yy00yy */
-	por %%mm5, %%mm2;          /* Overlay new u byte 0x0000000000uu00uu */
-
-/* mm0: 0x000000yy00yy00yy mm1: 0x000000vv00vv0000 mm2: 0x0000000000uu00uu */
- 	psubw _mpeg3_MMX_V_80_RGB, %%mm1;    /* Subtract 128 from v 0x000000vv00vv0000 */
- 	pmullw _mpeg3_MMX_V_COEF_RGB, %%mm1; /* Multiply v coeffs 0x0000vvvvvvvv0000 */
- 	psllw $6, %%mm0;                /* Shift y coeffs 0x0000yyy0yyy0yyy0 */
- 	psubw _mpeg3_MMX_U_80_RGB, %%mm2;    /* Subtract 128 from u 0x0000000000uu00uu */
- 	pmullw _mpeg3_MMX_U_COEF_RGB, %%mm2; /* Multiply u coeffs 0x0000uuuuuuuuuuuu */
-
-/* mm0: 0x000000yy00yy00yy mm1: 0x0000vvvvvvvv0000 mm2: 0x00000000uuuuuuuu */
-	paddsw %%mm1, %%mm0;        /* Add v to result */
-	paddsw %%mm2, %%mm0;        /* Add u to result 0x0000bbbbggggrrrr */
-	psraw $6, %%mm0;           /* Demote precision */
-	packuswb %%mm0, %%mm0;     /* Pack into RGBA 0x0000000000bbggrr */
-	movd %%mm0, (%3);          /* Store output */
+asm("\
+/* Output will be 0x00bbggrr with the 00 trailing so this can also be used */\
+/* for rgb24. */\
+	movd (%0), %%mm0;          /* Load y   0x00000000000000yy */\
+	movd (%1), %%mm1;          /* Load v    0x00000000000000vv */\
+	movq %%mm0, %%mm3;         /* Copy y to temp */\
+	psllq $16, %%mm1;          /* Shift v   0x0000000000vv0000 */\
+	movd (%2), %%mm2;          /* Load u    0x00000000000000uu */\
+	psllq $16, %%mm3;          /* Shift y */\
+	movq %%mm1, %%mm4;         /* Copy v to temp */\
+	por %%mm3, %%mm0;          /* Overlay new y byte 0x0000000000yy00yy */\
+	psllq $16, %%mm4;          /* Shift v */\
+	movq %%mm2, %%mm5;         /* Copy u to temp */\
+	psllq $16, %%mm3;          /* Shift y  */\
+	por %%mm4, %%mm1;          /* Overlay new v byte 0x000000vv00vv0000 */\
+	psllq $16, %%mm5;          /* Shift u  */\
+	por %%mm3, %%mm0;          /* Overlay new y byte 0x000000yy00yy00yy */\
+	por %%mm5, %%mm2;          /* Overlay new u byte 0x0000000000uu00uu */\
+\
+/* mm0: 0x000000yy00yy00yy mm1: 0x000000vv00vv0000 mm2: 0x0000000000uu00uu */\
+ 	psubw _mpeg3_MMX_V_80_RGB, %%mm1;    /* Subtract 128 from v 0x000000vv00vv0000 */\
+ 	pmullw _mpeg3_MMX_V_COEF_RGB, %%mm1; /* Multiply v coeffs 0x0000vvvvvvvv0000 */\
+ 	psllw $6, %%mm0;                /* Shift y coeffs 0x0000yyy0yyy0yyy0 */\
+ 	psubw _mpeg3_MMX_U_80_RGB, %%mm2;    /* Subtract 128 from u 0x0000000000uu00uu */\
+ 	pmullw _mpeg3_MMX_U_COEF_RGB, %%mm2; /* Multiply u coeffs 0x0000uuuuuuuuuuuu */\
+\
+/* mm0: 0x000000yy00yy00yy mm1: 0x0000vvvvvvvv0000 mm2: 0x00000000uuuuuuuu */\
+	paddsw %%mm1, %%mm0;        /* Add v to result */\
+	paddsw %%mm2, %%mm0;        /* Add u to result 0x0000bbbbggggrrrr */\
+	psraw $6, %%mm0;           /* Demote precision */\
+	packuswb %%mm0, %%mm0;     /* Pack into RGBA 0x0000000000bbggrr */\
+	movd %%mm0, (%3);          /* Store output */\
 	"
 :
 : "r" (&y), "r" (&v), "r" (&u), "r" (output));
@@ -393,39 +393,39 @@
 		unsigned long v, 
 		unsigned long *output)
 {
-asm("
-/* Output will be 0x00bbggrr with the 00 trailing so this can also be used */
-/* for rgb24. */
-	movd (%0), %%mm0;          /* Load y   0x00000000000000yy */
-	psubsw _mpeg3_MMX_601_Y_DIFF, %%mm0;      /* Subtract 16 from y */
-	movd (%1), %%mm1;          /* Load v    0x00000000000000vv */
-	movq %%mm0, %%mm3;         /* Copy y to temp */
-	psllq $16, %%mm1;          /* Shift v   0x0000000000vv0000 */
-	movd (%2), %%mm2;          /* Load u    0x00000000000000uu */
-	psllq $16, %%mm3;          /* Shift y */
-	movq %%mm1, %%mm4;         /* Copy v to temp */
-	por %%mm3, %%mm0;          /* Overlay new y byte 0x0000000000yy00yy */
-	psllq $16, %%mm4;          /* Shift v */
-	movq %%mm2, %%mm5;         /* Copy u to temp */
-	psllq $16, %%mm3;          /* Shift y  */
-	por %%mm4, %%mm1;          /* Overlay new v byte 0x000000vv00vv0000 */
-	psllq $16, %%mm5;          /* Shift u  */
-	por %%mm3, %%mm0;          /* Overlay new y byte 0x000000yy00yy00yy */
-	por %%mm5, %%mm2;          /* Overlay new u byte 0x0000000000uu00uu */
-
-/* mm0: 0x000000yy00yy00yy     mm1: 0x000000vv00vv0000     mm2: 0x0000000000uu00uu */
-	pmullw _mpeg3_MMX_601_Y_COEF, %%mm0;     /* Scale y coeffs */
- 	psubw _mpeg3_MMX_V_80_RGB, %%mm1;    /* Subtract 128 from v 0x000000vv00vv0000 */
- 	pmullw _mpeg3_MMX_V_COEF_RGB, %%mm1; /* Multiply v coeffs 0x0000vvvvvvvv0000 */
- 	psubw _mpeg3_MMX_U_80_RGB, %%mm2;    /* Subtract 128 from u 0x0000000000uu00uu */
- 	pmullw _mpeg3_MMX_U_COEF_RGB, %%mm2; /* Multiply u coeffs 0x0000uuuuuuuuuuuu */
-
-/* mm0: 0x000000yy00yy00yy mm1: 0x0000vvvvvvvv0000 mm2: 0x00000000uuuuuuuu */
-	paddsw %%mm1, %%mm0;        /* Add v to result */
-	paddsw %%mm2, %%mm0;        /* Add u to result 0x0000bbbbggggrrrr */
-	psraw $6, %%mm0;           /* Demote precision */
-	packuswb %%mm0, %%mm0;     /* Pack into RGBA 0x0000000000bbggrr */
-	movd %%mm0, (%3);          /* Store output */
+asm("\
+/* Output will be 0x00bbggrr with the 00 trailing so this can also be used */\
+/* for rgb24. */\
+	movd (%0), %%mm0;          /* Load y   0x00000000000000yy */\
+	psubsw _mpeg3_MMX_601_Y_DIFF, %%mm0;      /* Subtract 16 from y */\
+	movd (%1), %%mm1;          /* Load v    0x00000000000000vv */\
+	movq %%mm0, %%mm3;         /* Copy y to temp */\
+	psllq $16, %%mm1;          /* Shift v   0x0000000000vv0000 */\
+	movd (%2), %%mm2;          /* Load u    0x00000000000000uu */\
+	psllq $16, %%mm3;          /* Shift y */\
+	movq %%mm1, %%mm4;         /* Copy v to temp */\
+	por %%mm3, %%mm0;          /* Overlay new y byte 0x0000000000yy00yy */\
+	psllq $16, %%mm4;          /* Shift v */\
+	movq %%mm2, %%mm5;         /* Copy u to temp */\
+	psllq $16, %%mm3;          /* Shift y  */\
+	por %%mm4, %%mm1;          /* Overlay new v byte 0x000000vv00vv0000 */\
+	psllq $16, %%mm5;          /* Shift u  */\
+	por %%mm3, %%mm0;          /* Overlay new y byte 0x000000yy00yy00yy */\
+	por %%mm5, %%mm2;          /* Overlay new u byte 0x0000000000uu00uu */\
+\
+/* mm0: 0x000000yy00yy00yy     mm1: 0x000000vv00vv0000     mm2: 0x0000000000uu00uu */\
+	pmullw _mpeg3_MMX_601_Y_COEF, %%mm0;     /* Scale y coeffs */\
+ 	psubw _mpeg3_MMX_V_80_RGB, %%mm1;    /* Subtract 128 from v 0x000000vv00vv0000 */\
+ 	pmullw _mpeg3_MMX_V_COEF_RGB, %%mm1; /* Multiply v coeffs 0x0000vvvvvvvv0000 */\
+ 	psubw _mpeg3_MMX_U_80_RGB, %%mm2;    /* Subtract 128 from u 0x0000000000uu00uu */\
+ 	pmullw _mpeg3_MMX_U_COEF_RGB, %%mm2; /* Multiply u coeffs 0x0000uuuuuuuuuuuu */\
+\
+/* mm0: 0x000000yy00yy00yy mm1: 0x0000vvvvvvvv0000 mm2: 0x00000000uuuuuuuu */\
+	paddsw %%mm1, %%mm0;        /* Add v to result */\
+	paddsw %%mm2, %%mm0;        /* Add u to result 0x0000bbbbggggrrrr */\
+	psraw $6, %%mm0;           /* Demote precision */\
+	packuswb %%mm0, %%mm0;     /* Pack into RGBA 0x0000000000bbggrr */\
+	movd %%mm0, (%3);          /* Store output */\
 	"
 :
 : "r" (&y), "r" (&v), "r" (&u), "r" (output));

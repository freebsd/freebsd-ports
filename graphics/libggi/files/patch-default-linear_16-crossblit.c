--- default/linear_16/crossblit.c.orig	Tue Oct 28 06:21:37 2003
+++ default/linear_16/crossblit.c	Tue Oct 28 06:23:43 2003
@@ -1278,67 +1278,67 @@
 				while (stopcol > dstp + 11) {
 				  void *dummy;
 				  __asm__ __volatile__(
-				   "movq  (%1), %%mm0\n\t
-                                    pxor  %%mm5, %%mm5\n\t
-                                    movq  8(%1), %%mm1\n\t
-                                    pxor  %%mm6, %%mm6\n\t
-                                    movq  16(%1), %%mm2\n\t
-                                    pxor  %%mm7, %%mm7\n\t
-                                    add   $24, %1\n\t
-
-                                    .Lleft%=:
-                                    cmp   $0, 8(%2)\n\t
-                                    je    .Lmiddle%=\n\t
-
-                                    movq  %%mm0, %%mm3\n\t
-                                    movq  %%mm1, %%mm4\n\t
-                                    psllw (%2), %%mm3\n\t
-                                    psllw (%2), %%mm4\n\t
-                                    pand  8(%2), %%mm3\n\t
-                                    pand  8(%2), %%mm4\n\t
-                                    por   %%mm3, %%mm5\n\t
-                                    movq  %%mm2, %%mm3\n\t
-                                    por   %%mm4, %%mm6\n\t
-                                    psllw (%2), %%mm3\n\t
-                                    pand  8(%2), %%mm3\n\t
-                                    cmp   $0, (%2)\n\t
-                                    por   %%mm3, %%mm7\n\t
-                                    je    .Lright%=\n\t
-                                    add   $16, %2\n\t
-                                    jmp   .Lleft%=\n\t
-
-                                    .Lmiddle%=:\n\t
-                                    cmp   $0, (%2)\n\t
-                                    je    .Lright%=\n\t
-
-                                    .Ldone%=:\n\t
-                                    movq  %%mm5, (%0)\n\t
-                                    movq  %%mm6, 8(%0)\n\t
-                                    movq  %%mm7, 16(%0)\n\t
-                                    add   $24, %0\n\t
-                                    jmp   .Lout%=\n\t
-
-                                    .Lright%=:\n\t
-                                    add   $16, %2\n\t
-                                    cmp   $0, 8(%2)\n\t
-                                    je    .Ldone%=\n\t
-
-                                    movq  %%mm0, %%mm3\n\t
-                                    movq  %%mm1, %%mm4\n\t
-                                    psrlw (%2), %%mm3\n\t
-                                    psrlw (%2), %%mm4\n\t
-                                    pand  8(%2), %%mm3\n\t
-                                    pand  8(%2), %%mm4\n\t
-                                    por   %%mm3, %%mm5\n\t
-                                    movq  %%mm2, %%mm3\n\t
-                                    por   %%mm4, %%mm6\n\t
-                                    psrlw (%2), %%mm3\n\t
-                                    pand  8(%2), %%mm3\n\t
-                                    por   %%mm3, %%mm7\n\t
-
-                                    jmp   .Lright%=\n\t
-
-                                    .Lout%=:\n\t
+				   "movq  (%1), %%mm0\n\t\
+                                    pxor  %%mm5, %%mm5\n\t\
+                                    movq  8(%1), %%mm1\n\t\
+                                    pxor  %%mm6, %%mm6\n\t\
+                                    movq  16(%1), %%mm2\n\t\
+                                    pxor  %%mm7, %%mm7\n\t\
+                                    add   $24, %1\n\t\
+\
+                                    .Lleft%=:\
+                                    cmp   $0, 8(%2)\n\t\
+                                    je    .Lmiddle%=\n\t\
+\
+                                    movq  %%mm0, %%mm3\n\t\
+                                    movq  %%mm1, %%mm4\n\t\
+                                    psllw (%2), %%mm3\n\t\
+                                    psllw (%2), %%mm4\n\t\
+                                    pand  8(%2), %%mm3\n\t\
+                                    pand  8(%2), %%mm4\n\t\
+                                    por   %%mm3, %%mm5\n\t\
+                                    movq  %%mm2, %%mm3\n\t\
+                                    por   %%mm4, %%mm6\n\t\
+                                    psllw (%2), %%mm3\n\t\
+                                    pand  8(%2), %%mm3\n\t\
+                                    cmp   $0, (%2)\n\t\
+                                    por   %%mm3, %%mm7\n\t\
+                                    je    .Lright%=\n\t\
+                                    add   $16, %2\n\t\
+                                    jmp   .Lleft%=\n\t\
+\
+                                    .Lmiddle%=:\n\t\
+                                    cmp   $0, (%2)\n\t\
+                                    je    .Lright%=\n\t\
+\
+                                    .Ldone%=:\n\t\
+                                    movq  %%mm5, (%0)\n\t\
+                                    movq  %%mm6, 8(%0)\n\t\
+                                    movq  %%mm7, 16(%0)\n\t\
+                                    add   $24, %0\n\t\
+                                    jmp   .Lout%=\n\t\
+\
+                                    .Lright%=:\n\t\
+                                    add   $16, %2\n\t\
+                                    cmp   $0, 8(%2)\n\t\
+                                    je    .Ldone%=\n\t\
+\
+                                    movq  %%mm0, %%mm3\n\t\
+                                    movq  %%mm1, %%mm4\n\t\
+                                    psrlw (%2), %%mm3\n\t\
+                                    psrlw (%2), %%mm4\n\t\
+                                    pand  8(%2), %%mm3\n\t\
+                                    pand  8(%2), %%mm4\n\t\
+                                    por   %%mm3, %%mm5\n\t\
+                                    movq  %%mm2, %%mm3\n\t\
+                                    por   %%mm4, %%mm6\n\t\
+                                    psrlw (%2), %%mm3\n\t\
+                                    pand  8(%2), %%mm3\n\t\
+                                    por   %%mm3, %%mm7\n\t\
+\
+                                    jmp   .Lright%=\n\t\
+\
+                                    .Lout%=:\n\t\
                                     emms\n\t"
 				   : "=qom" (dstp), "=qom" (srcp), "=q" (dummy)
 				   : "qom" (dstp), "qom" (srcp), "q" (tab)
@@ -1438,73 +1438,73 @@
 				  void *dummy;
 				  __asm__ __volatile__(
 
-				   "movq  (%1), %%mm0\n\t
-                                    movq  8(%1), %%mm1\n\t
-                                    movq  16(%1), %%mm2\n\t
-                                    movq  24(%1), %%mm3\n\t
-                                    add   $32, %1\n\t
-                                    pxor  %%mm7, %%mm7\n\t
-                                    pxor  %%mm6, %%mm6\n\t
-
-                                    .Lleft%=:
-                                    cmp   $0, 8(%2)\n\t
-                                    je    .Lmiddle%=\n\t
-
-                                    movq  %%mm1, %%mm4\n\t
-                                    movq  %%mm0, %%mm5\n\t
-                                    pslld (%2), %%mm4\n\t
-                                    pslld (%2), %%mm5\n\t
-                                    psrad $16, %%mm4\n\t
-                                    psrad $16, %%mm5\n\t
-                                    packssdw %%mm4, %%mm5\n\t
-                                    movq  %%mm3, %%mm4\n\t
-                                    pand  8(%2), %%mm5\n\t
-                                    por   %%mm5, %%mm6\n\t
-                                    movq  %%mm2, %%mm5\n\t
-                                    pslld (%2), %%mm4\n\t
-                                    pslld (%2), %%mm5\n\t
-                                    psrad $16, %%mm4\n\t
-                                    psrad $16, %%mm5\n\t
-                                    packssdw %%mm4, %%mm5\n\t
-                                    pand  8(%2), %%mm5\n\t
-                                    cmp   $0, (%2)\n\t
-                                    por   %%mm5, %%mm7\n\t
-                                    je    .Lright%=\n\t
-                                    add   $16, %2\n\t
-                                    jmp   .Lleft%=\n\t
-
-                                    .Lmiddle%=:\n\t
-                                    cmp   $0, (%2)\n\t
-                                    je    .Lright%=\n\t
-
-                                    .Ldone%=:\n\t
-                                    movq  %%mm6, (%0)\n\t
-                                    movq  %%mm7, 8(%0)\n\t
-                                    add   $16, %0\n\t
-                                    jmp   .Lout%=\n\t
-
-                                    .Lright%=:\n\t
-                                    add   $16, %2\n\t
-                                    cmp   $0, 8(%2)\n\t
-                                    je    .Ldone%=\n\t
-
-                                    movq  %%mm1, %%mm4\n\t
-                                    movq  %%mm0, %%mm5\n\t
-                                    psrld (%2), %%mm4\n\t
-                                    psrld (%2), %%mm5\n\t
-                                    packssdw %%mm4, %%mm5\n\t
-                                    movq  %%mm3, %%mm4\n\t
-                                    pand  8(%2), %%mm5\n\t
-                                    por   %%mm5, %%mm6\n\t
-                                    movq  %%mm2, %%mm5\n\t
-                                    psrld (%2), %%mm4\n\t
-                                    psrld (%2), %%mm5\n\t
-                                    packssdw %%mm4, %%mm5\n\t
-                                    pand  8(%2), %%mm5\n\t
-                                    por   %%mm5, %%mm7\n\t
-                                    jmp   .Lright%=\n\t
-
-                                    .Lout%=:\n\t
+				   "movq  (%1), %%mm0\n\t\
+                                    movq  8(%1), %%mm1\n\t\
+                                    movq  16(%1), %%mm2\n\t\
+                                    movq  24(%1), %%mm3\n\t\
+                                    add   $32, %1\n\t\
+                                    pxor  %%mm7, %%mm7\n\t\
+                                    pxor  %%mm6, %%mm6\n\t\
+\
+                                    .Lleft%=:\\
+                                    cmp   $0, 8(%2)\n\t\\
+                                    je    .Lmiddle%=\n\t\\
+\
+                                    movq  %%mm1, %%mm4\n\t\
+                                    movq  %%mm0, %%mm5\n\t\
+                                    pslld (%2), %%mm4\n\t\
+                                    pslld (%2), %%mm5\n\t\
+                                    psrad $16, %%mm4\n\t\
+                                    psrad $16, %%mm5\n\t\
+                                    packssdw %%mm4, %%mm5\n\t\
+                                    movq  %%mm3, %%mm4\n\t\
+                                    pand  8(%2), %%mm5\n\t\
+                                    por   %%mm5, %%mm6\n\t\
+                                    movq  %%mm2, %%mm5\n\t\
+                                    pslld (%2), %%mm4\n\t\
+                                    pslld (%2), %%mm5\n\t\
+                                    psrad $16, %%mm4\n\t\
+                                    psrad $16, %%mm5\n\t\
+                                    packssdw %%mm4, %%mm5\n\t\
+                                    pand  8(%2), %%mm5\n\t\
+                                    cmp   $0, (%2)\n\t\
+                                    por   %%mm5, %%mm7\n\t\
+                                    je    .Lright%=\n\t\
+                                    add   $16, %2\n\t\
+                                    jmp   .Lleft%=\n\t\
+\
+                                    .Lmiddle%=:\n\t\
+                                    cmp   $0, (%2)\n\t\
+                                    je    .Lright%=\n\t\
+\
+                                    .Ldone%=:\n\t\
+                                    movq  %%mm6, (%0)\n\t\
+                                    movq  %%mm7, 8(%0)\n\t\
+                                    add   $16, %0\n\t\
+                                    jmp   .Lout%=\n\t\
+\
+                                    .Lright%=:\n\t\
+                                    add   $16, %2\n\t\
+                                    cmp   $0, 8(%2)\n\t\
+                                    je    .Ldone%=\n\t\
+\
+                                    movq  %%mm1, %%mm4\n\t\
+                                    movq  %%mm0, %%mm5\n\t\
+                                    psrld (%2), %%mm4\n\t\
+                                    psrld (%2), %%mm5\n\t\
+                                    packssdw %%mm4, %%mm5\n\t\
+                                    movq  %%mm3, %%mm4\n\t\
+                                    pand  8(%2), %%mm5\n\t\
+                                    por   %%mm5, %%mm6\n\t\
+                                    movq  %%mm2, %%mm5\n\t\
+                                    psrld (%2), %%mm4\n\t\
+                                    psrld (%2), %%mm5\n\t\
+                                    packssdw %%mm4, %%mm5\n\t\
+                                    pand  8(%2), %%mm5\n\t\
+                                    por   %%mm5, %%mm7\n\t\
+                                    jmp   .Lright%=\n\t\
+\
+                                    .Lout%=:\n\t\
                                     emms\n\t"
 				   : "=qom" (dstp), "=qom" (srcp), "=q" (dummy)
 				   : "qom" (dstp), "qom" (srcp), "q" (tab)

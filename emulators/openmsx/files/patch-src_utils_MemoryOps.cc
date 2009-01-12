--- src/utils/MemoryOps.cc.orig	2009-01-10 02:09:59.000000000 +0100
+++ src/utils/MemoryOps.cc	2009-01-10 02:09:03.000000000 +0100
@@ -79,7 +79,7 @@ static inline void memset_64_SSE(
 	}
 #ifdef ASM_X86_64
 	asm volatile (
-		"movq         %0, %%xmm0;"
+		"movd         %0, %%xmm0;"
 		"unpcklps %%xmm0, %%xmm0;"
 		: // no output
 		: "r" (val)

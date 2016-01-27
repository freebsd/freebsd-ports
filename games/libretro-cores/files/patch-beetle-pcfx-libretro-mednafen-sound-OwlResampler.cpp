--- beetle-pcfx-libretro/mednafen/sound/OwlResampler.cpp.orig	2015-10-16 02:50:34.000000000 +0200
+++ beetle-pcfx-libretro/mednafen/sound/OwlResampler.cpp	2016-01-23 21:47:18.614641000 +0100
@@ -346,7 +346,7 @@ static INLINE void DoMAC_SSE(float *wave
 "movups  0(%%" X86_REGC "di), %%xmm0\n\t"
 "movups 16(%%" X86_REGC "di), %%xmm1\n\t"
 
-"SSE_Loop:\n\t"
+"1:\n\t"
 
 "movups 32(%%" X86_REGC "di), %%xmm2\n\t"
 "mulps   0(%%" X86_REGC "si), %%xmm0\n\t"
@@ -384,7 +384,7 @@ static INLINE void DoMAC_SSE(float *wave
 "add" X86_REGAT " $128, %%" X86_REGC "si\n\t"
 "add" X86_REGAT " $128, %%" X86_REGC "di\n\t"
 "subl $1, %%ecx\n\t"
-"jnz SSE_Loop\n\t"
+"jnz 1b\n\t"
 
 "addps  %%xmm3, %%xmm7\n\t"	// For a loop optimization
 
@@ -451,7 +451,7 @@ static INLINE void DoMAC_SSE(float *wave
 "xorps %%xmm7, %%xmm7\n\t"
 
 "movups  0(%%" X86_REGC "di), %%xmm0\n\t"
-"SSE_Loop:\n\t"
+"1:\n\t"
 
 "movups 16(%%" X86_REGC "di), %%xmm1\n\t"
 "mulps   0(%%" X86_REGC "si), %%xmm0\n\t"
@@ -472,7 +472,7 @@ static INLINE void DoMAC_SSE(float *wave
 "add" X86_REGAT " $64, %%" X86_REGC "si\n\t"
 "add" X86_REGAT " $64, %%" X86_REGC "di\n\t"
 "subl $1, %%ecx\n\t"
-"jnz SSE_Loop\n\t"
+"jnz 1b\n\t"
 
 "addps  %%xmm3, %%xmm7\n\t"	// For a loop optimization
 

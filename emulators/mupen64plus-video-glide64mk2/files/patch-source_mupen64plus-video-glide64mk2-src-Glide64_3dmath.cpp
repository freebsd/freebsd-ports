--- source/mupen64plus-video-glide64mk2/src/Glide64/3dmath.cpp.orig	2015-04-26 22:42:57 UTC
+++ source/mupen64plus-video-glide64mk2/src/Glide64/3dmath.cpp
@@ -271,7 +271,7 @@ void MulMatricesSSE(float m1[4][4],float
     tmp = _mm_shuffle_ps (tmp, tmp, 3 + (3 << 2) + (3 << 4) + (3 << 6));
     destrow += tmp * row3;
 
-    __builtin_ia32_storeups(r[i], destrow);
+    _mm_storeu_ps(r[i], destrow);
   }
  #elif !defined(NO_ASM) && !defined(NOSSE)
   __asm

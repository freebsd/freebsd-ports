
$FreeBSD$

--- src/video/SDL_yuv_mmx.c.orig
+++ src/video/SDL_yuv_mmx.c
@@ -30,29 +30,35 @@
 
 #include "SDL_types.h"
 
-static unsigned int  MMX_0080w[]    = {0x00800080, 0x00800080};
-static unsigned int  MMX_00FFw[]    = {0x00ff00ff, 0x00ff00ff}; 
-static unsigned int  MMX_FF00w[]    = {0xff00ff00, 0xff00ff00}; 
+#ifdef __ELF__
+#define ASM_VAR(X) _##X
+#else
+#define ASM_VAR(X) X
+#endif
 
-static unsigned short MMX_Ycoeff[]  = {0x004a, 0x004a, 0x004a, 0x004a}; 
+static unsigned int  ASM_VAR(MMX_0080w)[]    = {0x00800080, 0x00800080};
+static unsigned int  ASM_VAR(MMX_00FFw)[]    = {0x00ff00ff, 0x00ff00ff};
+static unsigned int  ASM_VAR(MMX_FF00w)[]    = {0xff00ff00, 0xff00ff00};
 
-static unsigned short MMX_UbluRGB[] = {0x0072, 0x0072, 0x0072, 0x0072};    
-static unsigned short MMX_VredRGB[] = {0x0059, 0x0059, 0x0059, 0x0059};  
-static unsigned short MMX_UgrnRGB[] = {0xffea, 0xffea, 0xffea, 0xffea}; 
-static unsigned short MMX_VgrnRGB[] = {0xffd2, 0xffd2, 0xffd2, 0xffd2};  
+static unsigned short ASM_VAR(MMX_Ycoeff)[]  = {0x004a, 0x004a, 0x004a, 0x004a};
 
-static unsigned short MMX_Ublu5x5[] = {0x0081, 0x0081, 0x0081, 0x0081};
-static unsigned short MMX_Vred5x5[] = {0x0066, 0x0066, 0x0066, 0x0066};
-static unsigned short MMX_Ugrn555[] = {0xffe7, 0xffe7, 0xffe7, 0xffe7};
-static unsigned short MMX_Vgrn555[] = {0xffcc, 0xffcc, 0xffcc, 0xffcc};
-static unsigned short MMX_Ugrn565[] = {0xffe8, 0xffe8, 0xffe8, 0xffe8};
-static unsigned short MMX_Vgrn565[] = {0xffcd, 0xffcd, 0xffcd, 0xffcd};
+static unsigned short ASM_VAR(MMX_UbluRGB)[] = {0x0072, 0x0072, 0x0072, 0x0072};
+static unsigned short ASM_VAR(MMX_VredRGB)[] = {0x0059, 0x0059, 0x0059, 0x0059};
+static unsigned short ASM_VAR(MMX_UgrnRGB)[] = {0xffea, 0xffea, 0xffea, 0xffea};
+static unsigned short ASM_VAR(MMX_VgrnRGB)[] = {0xffd2, 0xffd2, 0xffd2, 0xffd2};
 
-static unsigned short MMX_red555[]  = {0x7c00, 0x7c00, 0x7c00, 0x7c00};
-static unsigned short MMX_red565[]  = {0xf800, 0xf800, 0xf800, 0xf800};
-static unsigned short MMX_grn555[]  = {0x03e0, 0x03e0, 0x03e0, 0x03e0};
-static unsigned short MMX_grn565[]  = {0x07e0, 0x07e0, 0x07e0, 0x07e0};
-static unsigned short MMX_blu5x5[]  = {0x001f, 0x001f, 0x001f, 0x001f};
+static unsigned short ASM_VAR(MMX_Ublu5x5)[] = {0x0081, 0x0081, 0x0081, 0x0081};
+static unsigned short ASM_VAR(MMX_Vred5x5)[] = {0x0066, 0x0066, 0x0066, 0x0066};
+static unsigned short ASM_VAR(MMX_Ugrn555)[] = {0xffe7, 0xffe7, 0xffe7, 0xffe7};
+static unsigned short ASM_VAR(MMX_Vgrn555)[] = {0xffcc, 0xffcc, 0xffcc, 0xffcc};
+static unsigned short ASM_VAR(MMX_Ugrn565)[] = {0xffe8, 0xffe8, 0xffe8, 0xffe8};
+static unsigned short ASM_VAR(MMX_Vgrn565)[] = {0xffcd, 0xffcd, 0xffcd, 0xffcd};
+
+static unsigned short ASM_VAR(MMX_red555)[]  = {0x7c00, 0x7c00, 0x7c00, 0x7c00};
+static unsigned short ASM_VAR(MMX_red565)[]  = {0xf800, 0xf800, 0xf800, 0xf800};
+static unsigned short ASM_VAR(MMX_grn555)[]  = {0x03e0, 0x03e0, 0x03e0, 0x03e0};
+static unsigned short ASM_VAR(MMX_grn565)[]  = {0x07e0, 0x07e0, 0x07e0, 0x07e0};
+static unsigned short ASM_VAR(MMX_blu5x5)[]  = {0x001f, 0x001f, 0x001f, 0x001f};
 
 /**
    This MMX assembler is my first assembler/MMX program ever.
@@ -114,12 +120,12 @@
 		 "movd (%2), %%mm2\n"           //    0  0  0  0 l3 l2 l1 l0
 		 "punpcklbw %%mm7,%%mm1\n" //         0  v3 0  v2 00 v1 00 v0
 		 "punpckldq %%mm1,%%mm1\n" //         00 v1 00 v0 00 v1 00 v0
-		 "psubw %[_MMX_0080w],%%mm1\n"  // mm1-128:r1 r1 r0 r0 r1 r1 r0 r0 
+		 "psubw _MMX_0080w,%%mm1\n"  // mm1-128:r1 r1 r0 r0 r1 r1 r0 r0 
 
 		 // create Cr_g (result in mm0)
 		 "movq %%mm1,%%mm0\n"           // r1 r1 r0 r0 r1 r1 r0 r0
-		 "pmullw %[_MMX_VgrnRGB],%%mm0\n"// red*-46dec=0.7136*64
-		 "pmullw %[_MMX_VredRGB],%%mm1\n"// red*89dec=1.4013*64
+		 "pmullw _MMX_VgrnRGB,%%mm0\n"// red*-46dec=0.7136*64
+		 "pmullw _MMX_VredRGB,%%mm1\n"// red*89dec=1.4013*64
 		 "psraw  $6, %%mm0\n"           // red=red/64
 		 "psraw  $6, %%mm1\n"           // red=red/64
 		 
@@ -128,8 +134,8 @@
 		 "movq (%2,%4),%%mm3\n"         //    0  0  0  0 L3 L2 L1 L0
 		 "punpckldq %%mm3,%%mm2\n"      //   L3 L2 L1 L0 l3 l2 l1 l0
 		 "movq %%mm2,%%mm4\n"           //   L3 L2 L1 L0 l3 l2 l1 l0
-		 "pand %[_MMX_FF00w],%%mm2\n"      //   L3 0  L1  0 l3  0 l1  0
-		 "pand %[_MMX_00FFw],%%mm4\n"      //   0  L2  0 L0  0 l2  0 l0
+		 "pand _MMX_FF00w,%%mm2\n"      //   L3 0  L1  0 l3  0 l1  0
+		 "pand _MMX_00FFw,%%mm4\n"      //   0  L2  0 L0  0 l2  0 l0
 		 "psrlw $8,%%mm2\n"             //   0  L3  0 L1  0 l3  0 l1
 
 		 // create R (result in mm6)
@@ -146,11 +152,11 @@
 		 "movd (%1), %%mm1\n"      //         0  0  0  0  u3 u2 u1 u0
 		 "punpcklbw %%mm7,%%mm1\n" //         0  u3 0  u2 00 u1 00 u0
 		 "punpckldq %%mm1,%%mm1\n" //         00 u1 00 u0 00 u1 00 u0
-		 "psubw %[_MMX_0080w],%%mm1\n"  // mm1-128:u1 u1 u0 u0 u1 u1 u0 u0 
+		 "psubw _MMX_0080w,%%mm1\n"  // mm1-128:u1 u1 u0 u0 u1 u1 u0 u0 
 		 // create Cb_g (result in mm5)
 		 "movq %%mm1,%%mm5\n"            // u1 u1 u0 u0 u1 u1 u0 u0
-		 "pmullw %[_MMX_UgrnRGB],%%mm5\n"    // blue*-109dec=1.7129*64
-		 "pmullw %[_MMX_UbluRGB],%%mm1\n"    // blue*114dec=1.78125*64
+		 "pmullw _MMX_UgrnRGB,%%mm5\n"    // blue*-109dec=1.7129*64
+		 "pmullw _MMX_UbluRGB,%%mm1\n"    // blue*114dec=1.78125*64
 		 "psraw  $6, %%mm5\n"            // blue=red/64
 		 "psraw  $6, %%mm1\n"            // blue=blue/64
 
@@ -232,14 +238,8 @@
 		 "popl %%ebx\n"
 		 :
 		 : "m" (cr), "r"(cb),"r"(lum),
-		   "r"(row1),"r"(cols),"r"(row2),"m"(x),"m"(y),"m"(mod),
-                   [_MMX_0080w] "m" (*MMX_0080w),
-                   [_MMX_00FFw] "m" (*MMX_00FFw),
-                   [_MMX_FF00w] "m" (*MMX_FF00w),
-                   [_MMX_VgrnRGB] "m" (*MMX_VgrnRGB),
-                   [_MMX_VredRGB] "m" (*MMX_VredRGB),
-                   [_MMX_UgrnRGB] "m" (*MMX_UgrnRGB),
-                   [_MMX_UbluRGB] "m" (*MMX_UbluRGB)
+		 "r"(row1),"r"(cols),"r"(row2),"m"(x),"m"(y),"m"(mod)
+		 : "%ebx"
 		 );
 }
 
@@ -269,21 +269,21 @@
          "movd           (%%ebx),                %%mm1\n" // 4 Cr                0  0  0  0 v3 v2 v1 v0
          "punpcklbw      %%mm7,                  %%mm0\n" // 4 W cb   0 u3  0 u2  0 u1  0 u0
          "punpcklbw      %%mm7,                  %%mm1\n" // 4 W cr   0 v3  0 v2  0 v1  0 v0
-         "psubw          %[_MMX_0080w],             %%mm0\n"
-         "psubw          %[_MMX_0080w],             %%mm1\n"
+         "psubw          _MMX_0080w,             %%mm0\n"
+         "psubw          _MMX_0080w,             %%mm1\n"
          "movq           %%mm0,                  %%mm2\n" // Cb                   0 u3  0 u2  0 u1  0 u0
          "movq           %%mm1,                  %%mm3\n" // Cr
-         "pmullw         %[_MMX_Ugrn565],           %%mm2\n" // Cb2green 0 R3  0 R2  0 R1  0 R0
+         "pmullw         _MMX_Ugrn565,           %%mm2\n" // Cb2green 0 R3  0 R2  0 R1  0 R0
          "movq           (%2),                   %%mm6\n" // L1      l7 L6 L5 L4 L3 L2 L1 L0
-         "pmullw         %[_MMX_Ublu5x5],           %%mm0\n" // Cb2blue
-         "pand           %[_MMX_00FFw],             %%mm6\n" // L1      00 L6 00 L4 00 L2 00 L0
-         "pmullw         %[_MMX_Vgrn565],           %%mm3\n" // Cr2green
+         "pmullw         _MMX_Ublu5x5,           %%mm0\n" // Cb2blue
+         "pand           _MMX_00FFw,             %%mm6\n" // L1      00 L6 00 L4 00 L2 00 L0
+         "pmullw         _MMX_Vgrn565,           %%mm3\n" // Cr2green
          "movq           (%2),                   %%mm7\n" // L2
-         "pmullw         %[_MMX_Vred5x5],           %%mm1\n" // Cr2red
+         "pmullw         _MMX_Vred5x5,           %%mm1\n" // Cr2red
          "psrlw          $8,                     %%mm7\n"        // L2           00 L7 00 L5 00 L3 00 L1
-         "pmullw         %[_MMX_Ycoeff],            %%mm6\n" // lum1
+         "pmullw         _MMX_Ycoeff,            %%mm6\n" // lum1
          "paddw          %%mm3,                  %%mm2\n" // Cb2green + Cr2green == green
-         "pmullw         %[_MMX_Ycoeff],            %%mm7\n" // lum2
+         "pmullw         _MMX_Ycoeff,            %%mm7\n" // lum2
 
          "movq           %%mm6,                  %%mm4\n" // lum1
          "paddw          %%mm0,                  %%mm6\n" // lum1 +blue 00 B6 00 B4 00 B2 00 B0
@@ -301,11 +301,11 @@
          "punpcklbw      %%mm4,                  %%mm4\n"
          "punpcklbw      %%mm5,                  %%mm5\n"
 
-         "pand           %[_MMX_red565],            %%mm4\n"
+         "pand           _MMX_red565,            %%mm4\n"
          "psllw          $3,                     %%mm5\n" // GREEN       1
          "punpcklbw      %%mm6,                  %%mm6\n"
-         "pand           %[_MMX_grn565],            %%mm5\n"
-         "pand           %[_MMX_red565],            %%mm6\n"
+         "pand           _MMX_grn565,            %%mm5\n"
+         "pand           _MMX_red565,            %%mm6\n"
          "por            %%mm5,                  %%mm4\n" //
          "psrlw          $11,                    %%mm6\n" // BLUE        1
          "movq           %%mm3,                  %%mm5\n" // lum2
@@ -319,23 +319,23 @@
          "packuswb       %%mm3,                  %%mm3\n"
          "packuswb       %%mm5,                  %%mm5\n"
          "packuswb       %%mm7,                  %%mm7\n"
-         "pand           %[_MMX_00FFw],             %%mm6\n" // L3
+         "pand           _MMX_00FFw,             %%mm6\n" // L3
          "punpcklbw      %%mm3,                  %%mm3\n"
          "punpcklbw      %%mm5,                  %%mm5\n"
-         "pmullw         %[_MMX_Ycoeff],            %%mm6\n" // lum3
+         "pmullw         _MMX_Ycoeff,            %%mm6\n" // lum3
          "punpcklbw      %%mm7,                  %%mm7\n"
          "psllw          $3,                     %%mm5\n" // GREEN 2
-         "pand           %[_MMX_red565],            %%mm7\n"
-         "pand           %[_MMX_red565],            %%mm3\n"
+         "pand           _MMX_red565,            %%mm7\n"
+         "pand           _MMX_red565,            %%mm3\n"
          "psrlw          $11,                    %%mm7\n" // BLUE  2
-         "pand           %[_MMX_grn565],            %%mm5\n"
+         "pand           _MMX_grn565,            %%mm5\n"
          "por            %%mm7,                  %%mm3\n"
          "movq           (%2,%4),                %%mm7\n" // L4 load lum2
          "por            %%mm5,                  %%mm3\n" //
          "psrlw          $8,                     %%mm7\n" // L4
          "movq           %%mm4,                  %%mm5\n"
          "punpcklwd      %%mm3,                  %%mm4\n"
-         "pmullw         %[_MMX_Ycoeff],            %%mm7\n" // lum4
+         "pmullw         _MMX_Ycoeff,            %%mm7\n" // lum4
          "punpckhwd      %%mm3,                  %%mm5\n"
 
          "movq           %%mm4,                  (%3)\n"  // write row1
@@ -362,11 +362,11 @@
          "punpcklbw      %%mm5,                  %%mm5\n"
          "punpcklbw      %%mm6,                  %%mm6\n"
          "psllw          $3,                     %%mm5\n" // GREEN 3
-         "pand           %[_MMX_red565],            %%mm4\n"
+         "pand           _MMX_red565,            %%mm4\n"
          "psraw          $6,                     %%mm3\n" // psr 6
          "psraw          $6,                     %%mm0\n"
-         "pand           %[_MMX_red565],            %%mm6\n" // BLUE
-         "pand           %[_MMX_grn565],            %%mm5\n"
+         "pand           _MMX_red565,            %%mm6\n" // BLUE
+         "pand           _MMX_grn565,            %%mm5\n"
          "psrlw          $11,                    %%mm6\n" // BLUE  3
          "por            %%mm5,                  %%mm4\n"
          "psraw          $6,                     %%mm7\n"
@@ -377,11 +377,11 @@
          "punpcklbw      %%mm3,                  %%mm3\n"
          "punpcklbw      %%mm0,                  %%mm0\n"
          "punpcklbw      %%mm7,                  %%mm7\n"
-         "pand           %[_MMX_red565],            %%mm3\n"
-         "pand           %[_MMX_red565],            %%mm7\n" // BLUE
+         "pand           _MMX_red565,            %%mm3\n"
+         "pand           _MMX_red565,            %%mm7\n" // BLUE
          "psllw          $3,                     %%mm0\n" // GREEN 4
          "psrlw          $11,                    %%mm7\n"
-         "pand           %[_MMX_grn565],            %%mm0\n"
+         "pand           _MMX_grn565,            %%mm0\n"
          "por            %%mm7,                  %%mm3\n"
          "por            %%mm0,                  %%mm3\n"
 
@@ -411,19 +411,11 @@
 	 "jl             1b\n"
          "emms\n"
 	 "popl %%ebx\n"
-	:
-	:"m" (cr), "r"(cb),"r"(lum),
-	 "r"(row1),"r"(cols),"r"(row2),"m"(x),"m"(y),"m"(mod),
-	 [_MMX_0080w] "m" (*MMX_0080w),
-	 [_MMX_Ugrn565] "m" (*MMX_Ugrn565),
-	 [_MMX_Ublu5x5] "m" (*MMX_Ublu5x5),
-	 [_MMX_00FFw] "m" (*MMX_00FFw),
-	 [_MMX_Vgrn565] "m" (*MMX_Vgrn565),
-	 [_MMX_Vred5x5] "m" (*MMX_Vred5x5),
-	 [_MMX_Ycoeff] "m" (*MMX_Ycoeff),
-	 [_MMX_red565] "m" (*MMX_red565),
-	 [_MMX_grn565] "m" (*MMX_grn565)
-         );
+	 :
+	 :"m" (cr), "r"(cb),"r"(lum),
+	 "r"(row1),"r"(cols),"r"(row2),"m"(x),"m"(y),"m"(mod)
+         : "%ebx"
+	 );
 }
 
 #endif /* GCC i386 inline assembly */

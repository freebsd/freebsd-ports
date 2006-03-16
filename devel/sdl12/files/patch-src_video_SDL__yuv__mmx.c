
$FreeBSD$

--- src/video/SDL_yuv_mmx.c.orig
+++ src/video/SDL_yuv_mmx.c
@@ -30,42 +30,31 @@
 
 #include "SDL_types.h"
 
-#if __GNUC__ > 2
-#    undef GCC2_HACK
-#else
-#    define GCC2_HACK
-#endif
-
- 
-#if defined(GCC2_HACK) && defined (__ELF__)
-#define ASM_VAR(X) _##X
-#else
-#define ASM_VAR(X) X
-#endif
+#define ASM_ARRAY(x) x[] __asm__("_" #x) __attribute__((used))
  
-static volatile unsigned int  ASM_VAR(MMX_0080w)[]    = {0x00800080, 0x00800080};
-static volatile unsigned int  ASM_VAR(MMX_00FFw)[]    = {0x00ff00ff, 0x00ff00ff}; 
-static volatile unsigned int  ASM_VAR(MMX_FF00w)[]    = {0xff00ff00, 0xff00ff00}; 
+static unsigned int  ASM_ARRAY(MMX_0080w)    = {0x00800080, 0x00800080};
+static unsigned int  ASM_ARRAY(MMX_00FFw)    = {0x00ff00ff, 0x00ff00ff};
+static unsigned int  ASM_ARRAY(MMX_FF00w)    = {0xff00ff00, 0xff00ff00};
 
-static volatile unsigned short ASM_VAR(MMX_Ycoeff)[]  = {0x004a, 0x004a, 0x004a, 0x004a}; 
+static unsigned short ASM_ARRAY(MMX_Ycoeff)  = {0x004a, 0x004a, 0x004a, 0x004a};
 
-static volatile unsigned short ASM_VAR(MMX_UbluRGB)[] = {0x0072, 0x0072, 0x0072, 0x0072};    
-static volatile unsigned short ASM_VAR(MMX_VredRGB)[] = {0x0059, 0x0059, 0x0059, 0x0059};  
-static volatile unsigned short ASM_VAR(MMX_UgrnRGB)[] = {0xffea, 0xffea, 0xffea, 0xffea}; 
-static volatile unsigned short ASM_VAR(MMX_VgrnRGB)[] = {0xffd2, 0xffd2, 0xffd2, 0xffd2};  
+static unsigned short ASM_ARRAY(MMX_UbluRGB) = {0x0072, 0x0072, 0x0072, 0x0072};
+static unsigned short ASM_ARRAY(MMX_VredRGB) = {0x0059, 0x0059, 0x0059, 0x0059};
+static unsigned short ASM_ARRAY(MMX_UgrnRGB) = {0xffea, 0xffea, 0xffea, 0xffea};
+static unsigned short ASM_ARRAY(MMX_VgrnRGB) = {0xffd2, 0xffd2, 0xffd2, 0xffd2};
 
-static volatile unsigned short ASM_VAR(MMX_Ublu5x5)[] = {0x0081, 0x0081, 0x0081, 0x0081};
-static volatile unsigned short ASM_VAR(MMX_Vred5x5)[] = {0x0066, 0x0066, 0x0066, 0x0066};
-static volatile unsigned short ASM_VAR(MMX_Ugrn555)[] = {0xffe7, 0xffe7, 0xffe7, 0xffe7};
-static volatile unsigned short ASM_VAR(MMX_Vgrn555)[] = {0xffcc, 0xffcc, 0xffcc, 0xffcc};
-static volatile unsigned short ASM_VAR(MMX_Ugrn565)[] = {0xffe8, 0xffe8, 0xffe8, 0xffe8};
-static volatile unsigned short ASM_VAR(MMX_Vgrn565)[] = {0xffcd, 0xffcd, 0xffcd, 0xffcd};
+static unsigned short ASM_ARRAY(MMX_Ublu5x5) = {0x0081, 0x0081, 0x0081, 0x0081};
+static unsigned short ASM_ARRAY(MMX_Vred5x5) = {0x0066, 0x0066, 0x0066, 0x0066};
+static unsigned short ASM_ARRAY(MMX_Ugrn555) = {0xffe7, 0xffe7, 0xffe7, 0xffe7};
+static unsigned short ASM_ARRAY(MMX_Vgrn555) = {0xffcc, 0xffcc, 0xffcc, 0xffcc};
+static unsigned short ASM_ARRAY(MMX_Ugrn565) = {0xffe8, 0xffe8, 0xffe8, 0xffe8};
+static unsigned short ASM_ARRAY(MMX_Vgrn565) = {0xffcd, 0xffcd, 0xffcd, 0xffcd};
 
-static volatile unsigned short ASM_VAR(MMX_red555)[]  = {0x7c00, 0x7c00, 0x7c00, 0x7c00};
-static volatile unsigned short ASM_VAR(MMX_red565)[]  = {0xf800, 0xf800, 0xf800, 0xf800};
-static volatile unsigned short ASM_VAR(MMX_grn555)[]  = {0x03e0, 0x03e0, 0x03e0, 0x03e0};
-static volatile unsigned short ASM_VAR(MMX_grn565)[]  = {0x07e0, 0x07e0, 0x07e0, 0x07e0};
-static volatile unsigned short ASM_VAR(MMX_blu5x5)[]  = {0x001f, 0x001f, 0x001f, 0x001f};
+static unsigned short ASM_ARRAY(MMX_red555)  = {0x7c00, 0x7c00, 0x7c00, 0x7c00};
+static unsigned short ASM_ARRAY(MMX_red565)  = {0xf800, 0xf800, 0xf800, 0xf800};
+static unsigned short ASM_ARRAY(MMX_grn555)  = {0x03e0, 0x03e0, 0x03e0, 0x03e0};
+static unsigned short ASM_ARRAY(MMX_grn565)  = {0x07e0, 0x07e0, 0x07e0, 0x07e0};
+static unsigned short ASM_ARRAY(MMX_blu5x5)  = {0x001f, 0x001f, 0x001f, 0x001f};
 
 /**
    This MMX assembler is my first assembler/MMX program ever.
@@ -127,21 +116,12 @@
 		 "movd (%2), %%mm2\n"           //    0  0  0  0 l3 l2 l1 l0
 		 "punpcklbw %%mm7,%%mm1\n" //         0  v3 0  v2 00 v1 00 v0
 		 "punpckldq %%mm1,%%mm1\n" //         00 v1 00 v0 00 v1 00 v0
-#ifdef GCC2_HACK
 		 "psubw _MMX_0080w,%%mm1\n"  // mm1-128:r1 r1 r0 r0 r1 r1 r0 r0 
-#else
-		 "psubw %[_MMX_0080w],%%mm1\n"  // mm1-128:r1 r1 r0 r0 r1 r1 r0 r0 
-#endif
 
 		 // create Cr_g (result in mm0)
 		 "movq %%mm1,%%mm0\n"           // r1 r1 r0 r0 r1 r1 r0 r0
-#ifdef GCC2_HACK
 		 "pmullw _MMX_VgrnRGB,%%mm0\n"// red*-46dec=0.7136*64
 		 "pmullw _MMX_VredRGB,%%mm1\n"// red*89dec=1.4013*64
-#else
-		 "pmullw %[_MMX_VgrnRGB],%%mm0\n"// red*-46dec=0.7136*64
-		 "pmullw %[_MMX_VredRGB],%%mm1\n"// red*89dec=1.4013*64
-#endif
 		 "psraw  $6, %%mm0\n"           // red=red/64
 		 "psraw  $6, %%mm1\n"           // red=red/64
 		 
@@ -150,13 +130,8 @@
 		 "movq (%2,%4),%%mm3\n"         //    0  0  0  0 L3 L2 L1 L0
 		 "punpckldq %%mm3,%%mm2\n"      //   L3 L2 L1 L0 l3 l2 l1 l0
 		 "movq %%mm2,%%mm4\n"           //   L3 L2 L1 L0 l3 l2 l1 l0
-#ifdef GCC2_HACK
 		 "pand _MMX_FF00w,%%mm2\n"      //   L3 0  L1  0 l3  0 l1  0
 		 "pand _MMX_00FFw,%%mm4\n"      //   0  L2  0 L0  0 l2  0 l0
-#else
-		 "pand %[_MMX_FF00w],%%mm2\n"      //   L3 0  L1  0 l3  0 l1  0
-		 "pand %[_MMX_00FFw],%%mm4\n"      //   0  L2  0 L0  0 l2  0 l0
-#endif
 		 "psrlw $8,%%mm2\n"             //   0  L3  0 L1  0 l3  0 l1
 
 		 // create R (result in mm6)
@@ -173,20 +148,11 @@
 		 "movd (%1), %%mm1\n"      //         0  0  0  0  u3 u2 u1 u0
 		 "punpcklbw %%mm7,%%mm1\n" //         0  u3 0  u2 00 u1 00 u0
 		 "punpckldq %%mm1,%%mm1\n" //         00 u1 00 u0 00 u1 00 u0
-#ifdef GCC2_HACK
 		 "psubw _MMX_0080w,%%mm1\n"  // mm1-128:u1 u1 u0 u0 u1 u1 u0 u0 
-#else
-		 "psubw %[_MMX_0080w],%%mm1\n"  // mm1-128:u1 u1 u0 u0 u1 u1 u0 u0 
-#endif
 		 // create Cb_g (result in mm5)
 		 "movq %%mm1,%%mm5\n"            // u1 u1 u0 u0 u1 u1 u0 u0
-#ifdef GCC2_HACK
 		 "pmullw _MMX_UgrnRGB,%%mm5\n"    // blue*-109dec=1.7129*64
 		 "pmullw _MMX_UbluRGB,%%mm1\n"    // blue*114dec=1.78125*64
-#else
-		 "pmullw %[_MMX_UgrnRGB],%%mm5\n"    // blue*-109dec=1.7129*64
-		 "pmullw %[_MMX_UbluRGB],%%mm1\n"    // blue*114dec=1.78125*64
-#endif
 		 "psraw  $6, %%mm5\n"            // blue=red/64
 		 "psraw  $6, %%mm1\n"            // blue=blue/64
 
@@ -268,17 +234,7 @@
 		 "popl %%ebx\n"
 		 :
 		 : "m" (cr), "r"(cb),"r"(lum),
-		 "r"(row1),"r"(cols),"r"(row2),"m"(x),"m"(y),"m"(mod)
-#ifndef GCC2_HACK
-		 ,[_MMX_0080w] "m" (*MMX_0080w),
-		 [_MMX_00FFw] "m" (*MMX_00FFw),
-		 [_MMX_FF00w] "m" (*MMX_FF00w),
-		 [_MMX_VgrnRGB] "m" (*MMX_VgrnRGB),
-		 [_MMX_VredRGB] "m" (*MMX_VredRGB),
-		 [_MMX_UgrnRGB] "m" (*MMX_UgrnRGB),
-		 [_MMX_UbluRGB] "m" (*MMX_UbluRGB)
-#endif
-			 );
+		 "r"(row1),"r"(cols),"r"(row2),"m"(x),"m"(y),"m"(mod));
 }
 
 void Color565DitherYV12MMX1X( int *colortab, Uint32 *rgb_2_pix,
@@ -307,48 +263,21 @@
          "movd           (%%ebx),                %%mm1\n" // 4 Cr                0  0  0  0 v3 v2 v1 v0
          "punpcklbw      %%mm7,                  %%mm0\n" // 4 W cb   0 u3  0 u2  0 u1  0 u0
          "punpcklbw      %%mm7,                  %%mm1\n" // 4 W cr   0 v3  0 v2  0 v1  0 v0
-#ifdef GCC2_HACK
          "psubw          _MMX_0080w,             %%mm0\n"
          "psubw          _MMX_0080w,             %%mm1\n"
-#else
-         "psubw          %[_MMX_0080w],             %%mm0\n"
-         "psubw          %[_MMX_0080w],             %%mm1\n"
-#endif
          "movq           %%mm0,                  %%mm2\n" // Cb                   0 u3  0 u2  0 u1  0 u0
          "movq           %%mm1,                  %%mm3\n" // Cr
-#ifdef GCC2_HACK
          "pmullw         _MMX_Ugrn565,           %%mm2\n" // Cb2green 0 R3  0 R2  0 R1  0 R0
-#else
-         "pmullw         %[_MMX_Ugrn565],           %%mm2\n" // Cb2green 0 R3  0 R2  0 R1  0 R0
-#endif
          "movq           (%2),                   %%mm6\n" // L1      l7 L6 L5 L4 L3 L2 L1 L0
-#ifdef GCC2_HACK
          "pmullw         _MMX_Ublu5x5,           %%mm0\n" // Cb2blue
          "pand           _MMX_00FFw,             %%mm6\n" // L1      00 L6 00 L4 00 L2 00 L0
          "pmullw         _MMX_Vgrn565,           %%mm3\n" // Cr2green
-#else
-         "pmullw         %[_MMX_Ublu5x5],           %%mm0\n" // Cb2blue
-         "pand           %[_MMX_00FFw],             %%mm6\n" // L1      00 L6 00 L4 00 L2 00 L0
-         "pmullw         %[_MMX_Vgrn565],           %%mm3\n" // Cr2green
-#endif
          "movq           (%2),                   %%mm7\n" // L2
-#ifdef GCC2_HACK
          "pmullw         _MMX_Vred5x5,           %%mm1\n" // Cr2red
-#else
-         "pmullw         %[_MMX_Vred5x5],           %%mm1\n" // Cr2red
-#endif
          "psrlw          $8,                     %%mm7\n"        // L2           00 L7 00 L5 00 L3 00 L1
-#ifdef GCC2_HACK
          "pmullw         _MMX_Ycoeff,            %%mm6\n" // lum1
-#else
-         "pmullw         %[_MMX_Ycoeff],            %%mm6\n" // lum1
-#endif
          "paddw          %%mm3,                  %%mm2\n" // Cb2green + Cr2green == green
-#ifdef GCC2_HACK
          "pmullw         _MMX_Ycoeff,            %%mm7\n" // lum2
-#else
-         "pmullw         %[_MMX_Ycoeff],            %%mm7\n" // lum2
-#endif
 
          "movq           %%mm6,                  %%mm4\n" // lum1
          "paddw          %%mm0,                  %%mm6\n" // lum1 +blue 00 B6 00 B4 00 B2 00 B0
@@ -366,20 +295,11 @@
          "punpcklbw      %%mm4,                  %%mm4\n"
          "punpcklbw      %%mm5,                  %%mm5\n"
 
-#ifdef GCC2_HACK
          "pand           _MMX_red565,            %%mm4\n"
-#else
-         "pand           %[_MMX_red565],            %%mm4\n"
-#endif
          "psllw          $3,                     %%mm5\n" // GREEN       1
          "punpcklbw      %%mm6,                  %%mm6\n"
-#ifdef GCC2_HACK
          "pand           _MMX_grn565,            %%mm5\n"
          "pand           _MMX_red565,            %%mm6\n"
-#else
-         "pand           %[_MMX_grn565],            %%mm5\n"
-         "pand           %[_MMX_red565],            %%mm6\n"
-#endif
          "por            %%mm5,                  %%mm4\n" //
          "psrlw          $11,                    %%mm6\n" // BLUE        1
          "movq           %%mm3,                  %%mm5\n" // lum2
@@ -393,44 +313,23 @@
          "packuswb       %%mm3,                  %%mm3\n"
          "packuswb       %%mm5,                  %%mm5\n"
          "packuswb       %%mm7,                  %%mm7\n"
-#ifdef GCC2_HACK
          "pand           _MMX_00FFw,             %%mm6\n" // L3
-#else
-         "pand           %[_MMX_00FFw],             %%mm6\n" // L3
-#endif
          "punpcklbw      %%mm3,                  %%mm3\n"
          "punpcklbw      %%mm5,                  %%mm5\n"
-#ifdef GCC2_HACK
          "pmullw         _MMX_Ycoeff,            %%mm6\n" // lum3
-#else
-         "pmullw         %[_MMX_Ycoeff],            %%mm6\n" // lum3
-#endif
          "punpcklbw      %%mm7,                  %%mm7\n"
          "psllw          $3,                     %%mm5\n" // GREEN 2
-#ifdef GCC2_HACK
          "pand           _MMX_red565,            %%mm7\n"
          "pand           _MMX_red565,            %%mm3\n"
-#else
-         "pand           %[_MMX_red565],            %%mm7\n"
-         "pand           %[_MMX_red565],            %%mm3\n"
-#endif
          "psrlw          $11,                    %%mm7\n" // BLUE  2
-#ifdef GCC2_HACK
          "pand           _MMX_grn565,            %%mm5\n"
-#else
-         "pand           %[_MMX_grn565],            %%mm5\n"
-#endif
          "por            %%mm7,                  %%mm3\n"
          "movq           (%2,%4),                %%mm7\n" // L4 load lum2
          "por            %%mm5,                  %%mm3\n" //
          "psrlw          $8,                     %%mm7\n" // L4
          "movq           %%mm4,                  %%mm5\n"
          "punpcklwd      %%mm3,                  %%mm4\n"
-#ifdef GCC2_HACK
          "pmullw         _MMX_Ycoeff,            %%mm7\n" // lum4
-#else
-         "pmullw         %[_MMX_Ycoeff],            %%mm7\n" // lum4
-#endif
          "punpckhwd      %%mm3,                  %%mm5\n"
 
          "movq           %%mm4,                  (%3)\n"  // write row1
@@ -457,20 +356,11 @@
          "punpcklbw      %%mm5,                  %%mm5\n"
          "punpcklbw      %%mm6,                  %%mm6\n"
          "psllw          $3,                     %%mm5\n" // GREEN 3
-#ifdef GCC2_HACK
          "pand           _MMX_red565,            %%mm4\n"
-#else
-         "pand           %[_MMX_red565],            %%mm4\n"
-#endif
          "psraw          $6,                     %%mm3\n" // psr 6
          "psraw          $6,                     %%mm0\n"
-#ifdef GCC2_HACK
          "pand           _MMX_red565,            %%mm6\n" // BLUE
          "pand           _MMX_grn565,            %%mm5\n"
-#else
-         "pand           %[_MMX_red565],            %%mm6\n" // BLUE
-         "pand           %[_MMX_grn565],            %%mm5\n"
-#endif
          "psrlw          $11,                    %%mm6\n" // BLUE  3
          "por            %%mm5,                  %%mm4\n"
          "psraw          $6,                     %%mm7\n"
@@ -481,20 +371,11 @@
          "punpcklbw      %%mm3,                  %%mm3\n"
          "punpcklbw      %%mm0,                  %%mm0\n"
          "punpcklbw      %%mm7,                  %%mm7\n"
-#ifdef GCC2_HACK
          "pand           _MMX_red565,            %%mm3\n"
          "pand           _MMX_red565,            %%mm7\n" // BLUE
-#else
-         "pand           %[_MMX_red565],            %%mm3\n"
-         "pand           %[_MMX_red565],            %%mm7\n" // BLUE
-#endif
          "psllw          $3,                     %%mm0\n" // GREEN 4
          "psrlw          $11,                    %%mm7\n"
-#ifdef GCC2_HACK
          "pand           _MMX_grn565,            %%mm0\n"
-#else
-         "pand           %[_MMX_grn565],            %%mm0\n"
-#endif
          "por            %%mm7,                  %%mm3\n"
          "por            %%mm0,                  %%mm3\n"
 
@@ -526,21 +407,7 @@
 	 "popl %%ebx\n"
          :
          :"m" (cr), "r"(cb),"r"(lum),
-	 "r"(row1),"r"(cols),"r"(row2),"m"(x),"m"(y),"m"(mod)
-#ifndef GCC2_HACK
-	 ,[_MMX_0080w] "m" (*MMX_0080w),
-	 [_MMX_Ugrn565] "m" (*MMX_Ugrn565),
-	 [_MMX_Ublu5x5] "m" (*MMX_Ublu5x5),
-	 [_MMX_00FFw] "m" (*MMX_00FFw),
-	 [_MMX_Vgrn565] "m" (*MMX_Vgrn565),
-	 [_MMX_Vred5x5] "m" (*MMX_Vred5x5),
-	 [_MMX_Ycoeff] "m" (*MMX_Ycoeff),
-	 [_MMX_red565] "m" (*MMX_red565),
-	 [_MMX_grn565] "m" (*MMX_grn565)
-#endif
-		 );
+	 "r"(row1),"r"(cols),"r"(row2),"m"(x),"m"(y),"m"(mod));
 }
-
-#undef GCC2_HACK
 
 #endif /* GCC i386 inline assembly */

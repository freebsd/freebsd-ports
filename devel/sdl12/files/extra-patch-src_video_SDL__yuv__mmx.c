--- src/video/SDL_yuv_mmx.c.orig	Wed Feb 18 18:22:04 2004
+++ src/video/SDL_yuv_mmx.c	Sun May 16 19:19:48 2004
@@ -22,7 +22,7 @@
 
 #ifdef SAVE_RCSID
 static char rcsid =
- "@(#) $Id: SDL_yuv_mmx.c,v 1.5 2004/01/04 16:49:22 slouken Exp $";
+ "@(#) $Id: SDL_yuv_mmx.c,v 1.6 2004/05/16 17:19:48 slouken Exp $";
 #endif
 
 
@@ -120,12 +120,12 @@
 		 "movd (%2), %%mm2\n"           //    0  0  0  0 l3 l2 l1 l0
 		 "punpcklbw %%mm7,%%mm1\n" //         0  v3 0  v2 00 v1 00 v0
 		 "punpckldq %%mm1,%%mm1\n" //         00 v1 00 v0 00 v1 00 v0
-		 "psubw _MMX_0080w,%%mm1\n"  // mm1-128:r1 r1 r0 r0 r1 r1 r0 r0 
+		 "psubw %[_MMX_0080w],%%mm1\n"  // mm1-128:r1 r1 r0 r0 r1 r1 r0 r0 
 
 		 // create Cr_g (result in mm0)
 		 "movq %%mm1,%%mm0\n"           // r1 r1 r0 r0 r1 r1 r0 r0
-		 "pmullw _MMX_VgrnRGB,%%mm0\n"// red*-46dec=0.7136*64
-		 "pmullw _MMX_VredRGB,%%mm1\n"// red*89dec=1.4013*64
+		 "pmullw %[_MMX_VgrnRGB],%%mm0\n"// red*-46dec=0.7136*64
+		 "pmullw %[_MMX_VredRGB],%%mm1\n"// red*89dec=1.4013*64
 		 "psraw  $6, %%mm0\n"           // red=red/64
 		 "psraw  $6, %%mm1\n"           // red=red/64
 		 
@@ -134,8 +134,8 @@
 		 "movq (%2,%4),%%mm3\n"         //    0  0  0  0 L3 L2 L1 L0
 		 "punpckldq %%mm3,%%mm2\n"      //   L3 L2 L1 L0 l3 l2 l1 l0
 		 "movq %%mm2,%%mm4\n"           //   L3 L2 L1 L0 l3 l2 l1 l0
-		 "pand _MMX_FF00w,%%mm2\n"      //   L3 0  L1  0 l3  0 l1  0
-		 "pand _MMX_00FFw,%%mm4\n"      //   0  L2  0 L0  0 l2  0 l0
+		 "pand %[_MMX_FF00w],%%mm2\n"      //   L3 0  L1  0 l3  0 l1  0
+		 "pand %[_MMX_00FFw],%%mm4\n"      //   0  L2  0 L0  0 l2  0 l0
 		 "psrlw $8,%%mm2\n"             //   0  L3  0 L1  0 l3  0 l1
 
 		 // create R (result in mm6)
@@ -152,11 +152,11 @@
 		 "movd (%1), %%mm1\n"      //         0  0  0  0  u3 u2 u1 u0
 		 "punpcklbw %%mm7,%%mm1\n" //         0  u3 0  u2 00 u1 00 u0
 		 "punpckldq %%mm1,%%mm1\n" //         00 u1 00 u0 00 u1 00 u0
-		 "psubw _MMX_0080w,%%mm1\n"  // mm1-128:u1 u1 u0 u0 u1 u1 u0 u0 
+		 "psubw %[_MMX_0080w],%%mm1\n"  // mm1-128:u1 u1 u0 u0 u1 u1 u0 u0 
 		 // create Cb_g (result in mm5)
 		 "movq %%mm1,%%mm5\n"            // u1 u1 u0 u0 u1 u1 u0 u0
-		 "pmullw _MMX_UgrnRGB,%%mm5\n"    // blue*-109dec=1.7129*64
-		 "pmullw _MMX_UbluRGB,%%mm1\n"    // blue*114dec=1.78125*64
+		 "pmullw %[_MMX_UgrnRGB],%%mm5\n"    // blue*-109dec=1.7129*64
+		 "pmullw %[_MMX_UbluRGB],%%mm1\n"    // blue*114dec=1.78125*64
 		 "psraw  $6, %%mm5\n"            // blue=red/64
 		 "psraw  $6, %%mm1\n"            // blue=blue/64
 
@@ -238,8 +238,14 @@
 		 "popl %%ebx\n"
 		 :
 		 : "m" (cr), "r"(cb),"r"(lum),
-		 "r"(row1),"r"(cols),"r"(row2),"m"(x),"m"(y),"m"(mod)
-		 : "%ebx"
+		 "r"(row1),"r"(cols),"r"(row2),"m"(x),"m"(y),"m"(mod),
+         [_MMX_0080w] "m" (*_MMX_0080w),
+         [_MMX_00FFw] "m" (*_MMX_00FFw),
+         [_MMX_FF00w] "m" (*_MMX_FF00w),
+         [_MMX_VgrnRGB] "m" (*_MMX_VgrnRGB),
+         [_MMX_VredRGB] "m" (*_MMX_VredRGB),
+         [_MMX_UgrnRGB] "m" (*_MMX_UgrnRGB),
+         [_MMX_UbluRGB] "m" (*_MMX_UbluRGB)
 		 );
 }
 
@@ -413,8 +419,16 @@
 	 "popl %%ebx\n"
          :
          :"m" (cr), "r"(cb),"r"(lum),
-	 "r"(row1),"r"(cols),"r"(row2),"m"(x),"m"(y),"m"(mod)
-	 : "%ebx"
+	 "r"(row1),"r"(cols),"r"(row2),"m"(x),"m"(y),"m"(mod),
+     [_MMX_0080w] "m" (*_MMX_0080w),
+ [_MMX_Ugrn565] "m" (*_MMX_Ugrn565),
+ [_MMX_Ublu5x5] "m" (*_MMX_Ublu5x5),
+ [_MMX_00FFw] "m" (*_MMX_00FFw),
+ [_MMX_Vgrn565] "m" (*_MMX_Vgrn565),
+ [_MMX_Vred5x5] "m" (*_MMX_Vred5x5),
+ [_MMX_Ycoeff] "m" (*_MMX_Ycoeff),
+ [_MMX_red565] "m" (*_MMX_red565),
+ [_MMX_grn565] "m" (*_MMX_grn565)
          );
 }
 

--- DecodedMux.cpp.orig	Thu Aug 28 22:39:21 2003
+++ DecodedMux.cpp	Fri Aug 13 21:51:55 2004
@@ -760,7 +760,7 @@
 ShadeConstMergeMapType MergeShadeWithConstantsMaps[] =
 {
 	0,	SHADE_DO_NOTHING,
-	0x0007000600070006,	SHADE_MOD_ENV,		// SHADE * ENV
+	0x0007000600070006LL,	SHADE_MOD_ENV,		// SHADE * ENV
 };
 
 // 0x05070501, 0x00070006		//(1 - PRIM) * ENV + PRIM

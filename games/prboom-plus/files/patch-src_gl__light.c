--- src/gl_light.c.orig	2011-08-21 10:39:08 UTC
+++ src/gl_light.c
@@ -76,6 +76,8 @@ static float lighttable_glboom[5][256];
 static float lighttable_gzdoom[256];
 static float lighttable_fogbased[256];
 
+gld_Calc2DLightLevel_f gld_Calc2DLightLevel;
+
 static void gld_InitLightTable_glboom(void);
 static void gld_InitLightTable_gzdoom(void);
 static void gld_InitLightTable_fogbased(void);

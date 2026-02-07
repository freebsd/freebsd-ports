--- src/gl_intern.h.orig	2011-10-05 10:23:00 UTC
+++ src/gl_intern.h
@@ -450,8 +450,8 @@ void gld_StaticLightAlpha(float light, float alpha);
 void gld_InitLightTable(void);
 typedef float (*gld_CalcLightLevel_f)(int lightlevel);
 typedef float (*gld_Calc2DLightLevel_f)(int lightlevel);
-gld_CalcLightLevel_f gld_CalcLightLevel;
-gld_Calc2DLightLevel_f gld_Calc2DLightLevel;
+extern gld_CalcLightLevel_f gld_CalcLightLevel;
+extern gld_Calc2DLightLevel_f gld_Calc2DLightLevel;
 
 //fog
 extern int gl_fog;
@@ -459,7 +459,7 @@ extern int gl_use_fog;
 void gl_EnableFog(int on);
 void gld_SetFog(float fogdensity);
 typedef float (*gld_CalcFogDensity_f)(sector_t *sector, int lightlevel, GLDrawItemType type);
-gld_CalcFogDensity_f gld_CalcFogDensity;
+extern gld_CalcFogDensity_f gld_CalcFogDensity;
 
 //HQ resize
 unsigned char* gld_HQResize(GLTexture *gltexture, unsigned char *inputBuffer, int inWidth, int inHeight, int *outWidth, int *outHeight);

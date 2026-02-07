--- src/global.h.orig	2003-07-21 11:27:25 UTC
+++ src/global.h
@@ -38,7 +38,7 @@
 #define EXTERN extern
 #endif
 
-EXTERN char ConfigDir[255];
+extern char ConfigDir[255];
 
 EXTERN SDL_Rect OrigBlock_Rect; 
 EXTERN SDL_Rect Block_Rect;
@@ -70,9 +70,9 @@ EXTERN SDL_Rect ConsMenuItem_Rect;
 
 EXTERN float LastRefreshSound;
 EXTERN float LastGotIntoBlastSound;
-EXTERN float FPSover1;
-EXTERN float FPSover10;
-EXTERN float FPSover100;
+extern float FPSover1;
+extern float FPSover10;
+extern float FPSover100;
 EXTERN char *Alertcolor[AL_LAST];
 EXTERN char *Shipnames[ALLSHIPS];
 

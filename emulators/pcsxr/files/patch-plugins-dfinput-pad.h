--- plugins/dfinput/pad.h.orig	2020-09-07 22:26:22 UTC
+++ plugins/dfinput/pad.h
@@ -151,7 +151,7 @@ typedef struct tagKeyDef {
 enum { ANALOG_XP = 0, ANALOG_XM, ANALOG_YP, ANALOG_YM };
 
 #if SDL_VERSION_ATLEAST(2,0,0)
-SDL_GameControllerButton controllerMap[DKEY_TOTAL];	
+extern SDL_GameControllerButton controllerMap[DKEY_TOTAL];	
 #endif
 
 typedef struct tagPadDef {

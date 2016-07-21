--- src/main.c.orig	2016-01-10 17:37:25 UTC
+++ src/main.c
@@ -156,7 +156,7 @@ int main(int argc, char *argv[]) {
     INFO("Running on platform: %s", SDL_GetPlatform());
 
 #ifndef STANDALONE_SERVER
-    if(SDL_InitSubSystem(SDL_INIT_JOYSTICK|SDL_INIT_GAMECONTROLLER|SDL_INIT_HAPTIC)) {
+    if(SDL_InitSubSystem(SDL_INIT_JOYSTICK|SDL_INIT_GAMECONTROLLER)) {
         err_msgbox("SDL2 Initialization failed: %s", SDL_GetError());
         goto exit_2;
     }

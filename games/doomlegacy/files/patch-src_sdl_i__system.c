--- src/sdl/i_system.c.orig	2022-12-18 00:00:15 UTC
+++ src/sdl/i_system.c
@@ -932,6 +932,9 @@ void I_SysInit(void)
 
   // Enable unicode key conversion
   SDL_EnableUNICODE(1);
+
+  // Enable key auto repeat
+  SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
 #endif
 
   // Initialize the joystick subsystem.

--- sdl/i_system.c.orig	2014-05-16 20:11:49 UTC
+++ sdl/i_system.c
@@ -508,6 +508,8 @@ void I_SysInit(void)
 
   // Enable unicode key conversion
   SDL_EnableUNICODE(1);
+  // Enable key auto repeat
+  SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
 
   // Initialize the joystick subsystem.
   I_JoystickInit();

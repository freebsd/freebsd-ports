--- linux/sdllink.c.orig	Sun Sep 23 17:42:52 2001
+++ linux/sdllink.c	Tue May  7 13:16:21 2002
@@ -536,6 +536,11 @@
 
 	for (i = 0; i < 5; i++)
 		JoystickInput[i] = NULL;
+#if 1
+    printf("ZSNES could not find any joysticks.\n");
+    SDL_QuitSubSystem(SDL_INIT_JOYSTICK);
+    return FALSE;
+#else
 	// If it is possible to use SDL_NumJoysticks
 	// before initialising SDL_INIT_JOYSTICK then
 	// this call can be replaced with SDL_InitSubSystem
@@ -557,6 +562,7 @@
 	}
 
 	return TRUE;
+#endif
 }
 
 BOOL InitInput()
@@ -572,7 +578,11 @@
 	if (!sdl_inited)
 	{
 		if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_TIMER |
-	        SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)
+	        SDL_INIT_VIDEO
+#if 0
+| SDL_INIT_JOYSTICK
+#endif
+		) < 0)
 		{
 			fprintf(stderr, "Could not initialize SDL!\n");
 			return FALSE;

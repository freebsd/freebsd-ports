--- src/osd/sdl/input.c.orig
+++ src/osd/sdl/input.c
@@ -720,7 +720,11 @@
 	mame_printf_verbose("Joystick: Start initialization\n");
 	for (physical_stick = 0; physical_stick < SDL_NumJoysticks(); physical_stick++)
 	{
+#if (SDLMAME_SDL2)
+		char *joy_name = remove_spaces(machine, SDL_JoystickNameForIndex(physical_stick));
+#else
 		char *joy_name = remove_spaces(machine, SDL_JoystickName(physical_stick));
+#endif
 
 		devmap_register(&joy_map, physical_stick, joy_name);
 	}

--- Source_Files/Misc/screen_sdl.cpp.orig	Sat Apr 28 01:48:07 2001
+++ Source_Files/Misc/screen_sdl.cpp	Sat Apr 28 01:49:40 2001
@@ -625,7 +625,7 @@
 		build_sdl_color_table(color_table, colors);
 		SDL_SetPalette(main_surface, SDL_PHYSPAL, colors, 0, 256);
 	} else {
-#if SDL_PATCHLEVEL > 6
+#if SDL_VERSION_ATLEAST(1,1,7)
 		// SDL 1.1.7 defines these as 16-bit arrays...
 		uint16 red[256], green[256], blue[256];
 		for (int i=0; i<color_table->color_count; i++) {

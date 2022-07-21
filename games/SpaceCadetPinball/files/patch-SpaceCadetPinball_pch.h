Fix SDL_Mixer version detection broken after SDL_mixer 2.6.1.
This is already fixed in SpaceCadetPinball master after 2.0.1.
--- SpaceCadetPinball/pch.h.orig	2021-12-29 06:46:09 UTC
+++ SpaceCadetPinball/pch.h
@@ -37,11 +37,7 @@
 
 // MIX_INIT_FLUIDSYNTH was renamed to MIX_INIT_MID in SDL_mixer v2.0.2
 constexpr int MIX_INIT_MID_Proxy =
-#if SDL_MIXER_PATCHLEVEL >= 2
 	MIX_INIT_MID;
-#else
-	MIX_INIT_FLUIDSYNTH;
-#endif
 
 //https://github.com/ocornut/imgui 7b913db1ce9dd2fd98e5790aa59974dd4496be3b
 #include "imgui.h"

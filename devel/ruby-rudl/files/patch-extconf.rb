--- extconf.rb.orig	Wed Apr 11 08:36:36 2001
+++ extconf.rb	Tue Apr 17 22:01:42 2001
@@ -24,8 +24,7 @@
 have_header('SDL_image.h')
 have_header('SDL_mixer.h')
 
-if have_library('SDL', 'SDL_Quit') and 
-		have_library('SDLmain') and 
+if have_func('SDL_Quit') and 
 		have_header('SDL.h') then
 
 	create_makefile('RuDL')

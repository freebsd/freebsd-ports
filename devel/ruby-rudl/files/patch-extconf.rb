--- extconf.rb.orig	Wed May 16 02:55:22 2001
+++ extconf.rb	Wed May 16 03:51:59 2001
@@ -24,9 +24,7 @@
 have_header('SDL_image.h')
 have_header('SDL_mixer.h')
 
-if have_library('SDL', 'SDL_Quit') and 
-		have_library('SDLmain') and 
-		have_header('SDL.h') then
-
+if have_func('SDL_Quit') and 
+    have_header('SDL.h') then
 	create_makefile('RUDL')
 end

--- extconf.rb.orig	Wed Dec  7 11:12:50 2005
+++ extconf.rb	Wed Dec  7 11:14:10 2005
@@ -105,7 +105,7 @@
 
 puts '* Checking for required files'
 puts ' - SDL from http://www.libsdl.org/download-1.2.html'
-if have_library('SDL', 'SDL_Quit') and have_header('SDL.h')
+if have_func('SDL_Quit') and have_header('SDL.h')
     create_makefile('RUDL')
     puts '* Done! You may now run make.'
 else

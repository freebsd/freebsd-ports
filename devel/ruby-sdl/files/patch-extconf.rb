--- extconf.rb.orig	Sun Mar 25 17:10:56 2001
+++ extconf.rb	Tue Mar 27 01:16:54 2001
@@ -1,7 +1,9 @@
 require 'mkmf'
 
-$CFLAGS += `sdl-config --cflags`.chomp
-$LDFLAGS += `sdl-config --libs`.chomp
+sdl_config = with_config('sdl-config', 'sdl-config')
+
+$CFLAGS += `#{sdl_config} --cflags`.chomp
+$LDFLAGS += `#{sdl_config} --libs`.chomp
 
 if have_library("SDL_mixer","Mix_OpenAudio") then
   $CFLAGS+= " -D HAVE_SDL_MIXER "

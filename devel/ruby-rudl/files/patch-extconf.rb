--- extconf.rb.orig	Tue Apr 10 07:12:54 2001
+++ extconf.rb	Tue Apr 10 16:56:53 2001
@@ -5,20 +5,20 @@
 
 makeMakefile=false
 
-havePthread=have_library('pthread')
+sdl_config = with_config("sdl-config", "sdl-config")
 
-if have_library('SDL', 'SDL_Quit') and 
-		have_library('SDLmain') then
+have_library('pthread')
 
-	if /mswin32|cygwin/ =~ RUBY_PLATFORM then
-		# Make sure SDL.h is to be found somewhere!
-		makeMakefile=have_header('SDL.h')
-	else
-		$CFLAGS += `sdl-config --cflags`.chomp
-		$LDFLAGS += `sdl-config --libs`.chomp
-		makeMakefile=have_header('SDL.h') and havePthread
-	end
+if /mswin32|cygwin/ =~ RUBY_PLATFORM then
+	have_library('SDL', 'SDL_Quit')
+	have_library('SDLmain')
+else
+	$CFLAGS += `#{sdl_config} --cflags`.chomp
+	$LDFLAGS += `#{sdl_config} --libs`.chomp
 end
 
-if makeMakefile then create_makefile('RuDL') end
+if have_func('SDL_Quit') then
+	makeMakefile=have_header('SDL.h')
+end
 
+if makeMakefile then create_makefile('RuDL') end

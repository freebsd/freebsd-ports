--- extconf.rb.orig	Sat Sep 27 07:59:45 2003
+++ extconf.rb	Mon Apr 19 04:07:30 2004
@@ -52,14 +52,14 @@
 windows=mswin32||cygwin
 unix=!windows
 
-$CFLAGS+="-funroll-loops " if !mswin32
+$CFLAGS+=" -funroll-loops " if !mswin32
 
-$CFLAGS+="-Wall " if unix||cygwin
-$CPPFLAGS+="-GX " if mswin32
+$CFLAGS+=" -Wall " if unix||cygwin
+$CPPFLAGS+=" -GX " if mswin32
 
 if unix
-	$CFLAGS += `#{sdl_config} --cflags`.chomp
-	$LDFLAGS += `#{sdl_config} --libs`.chomp
+	$CFLAGS += " " + `#{sdl_config} --cflags`.chomp
+	$LDFLAGS += " " + `#{sdl_config} --libs`.chomp
 end
 
 puts '* Checking for optional files'
@@ -99,7 +99,7 @@
 
 puts '* Checking for required files'
 puts ' - SDL from http://www.libsdl.org/download-1.2.html'
-if have_library('SDL', 'SDL_Quit') and have_header('SDL.h')
+if have_func('SDL_Quit') and have_header('SDL.h')
 	create_makefile('RUDL')
 	puts '* Done! You may now run make.'
 else

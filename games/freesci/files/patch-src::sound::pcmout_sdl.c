--- src/gfx/drivers/sdl_driver.c.orig	Tue Feb  4 21:12:10 2003
+++ src/gfx/drivers/sdl_driver.c	Tue Feb  4 21:16:42 2003
@@ -45,7 +45,7 @@
 
 #ifndef _MSC_VER
 #	include <sys/time.h>
-#	include <SDL/SDL.h>
+#	include <SDL11/SDL.h>
 #else
 #	include <SDL.h>
 #endif
--- src/sound/thread_ss_sdl.c.orig	Tue Feb  4 21:15:31 2003
+++ src/sound/thread_ss_sdl.c	Tue Feb  4 21:16:25 2003
@@ -32,8 +32,8 @@
 #ifdef HAVE_SDL
 
 #ifndef _MSC_VER
-#  include <SDL/SDL.h>
-#  include <SDL/SDL_thread.h>
+#  include <SDL11/SDL.h>
+#  include <SDL11/SDL_thread.h>
 #  include <sys/timeb.h>
 #else
 #  include <SDL.h>
--- src/sound/pcmout_sdl.c.orig	Tue Feb  4 21:15:37 2003
+++ src/sound/pcmout_sdl.c	Tue Feb  4 21:16:32 2003
@@ -23,7 +23,7 @@
 
 #ifndef _MSC_VER
 #       include <sys/time.h>
-#       include <SDL/SDL.h>
+#       include <SDL11/SDL.h>
 #else
 #       include <SDL.h>
 #endif

--- Source_Files/Misc/thread_priority_sdl_posix.cpp.orig	Fri Aug 29 03:31:10 2003
+++ Source_Files/Misc/thread_priority_sdl_posix.cpp	Thu Jun 23 05:11:11 2005
@@ -12,7 +12,7 @@
 #if defined(TARGET_API_MAC_CARBON) && __MACH__
 #include <SDL/SDL_Thread.h>
 #else
-#include	<SDL/SDL_thread.h>
+#include	<SDL_thread.h>
 #endif
 
 #include	<pthread.h>

--- Source_Files/Misc/thread_priority_sdl_posix.cpp.orig	Wed Mar 23 10:41:58 2005
+++ Source_Files/Misc/thread_priority_sdl_posix.cpp	Wed Mar 23 10:42:10 2005
@@ -12,7 +12,7 @@
 #if defined(TARGET_API_MAC_CARBON) && __MACH__
 #include <SDL/SDL_Thread.h>
 #else
-#include	<SDL/SDL_thread.h>
+#include	<SDL_thread.h>
 #endif
 
 #include	<pthread.h>

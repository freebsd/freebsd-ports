
$FreeBSD$

--- source/unix/global_os.h.orig	Mon Sep  3 17:26:45 2001
+++ source/unix/global_os.h	Mon Sep  3 17:32:50 2001
@@ -53,8 +53,8 @@
  #define global_os_h_included
 
   #ifndef minimalIO
-   #define sdlheader "SDL/SDL.h"
-   #define sdlmixerheader "SDL/SDL_mixer.h"
+   #define sdlheader "SDL.h"
+   #define sdlmixerheader "SDL_mixer.h"
    #include sdlheader
   #endif 
 
@@ -77,7 +77,7 @@
   #endif
 
   #define CASE_SENSITIVE_FILE_NAMES 1
-  #define USE_HOME_DIRECTORY 1
+  #define USE_HOME_DIRECTORY 0
 
 
 #endif


$FreeBSD$

--- source/unix/global_os.h	2002/10/01 12:34:15	1.1
+++ source/unix/global_os.h	2002/10/01 12:34:29
@@ -60,8 +60,8 @@
  #define global_os_h_included
 
   #ifndef minimalIO
-   #define sdlheader "SDL/SDL.h"
-   #define sdlmixerheader "SDL/SDL_mixer.h"
+   #define sdlheader "SDL.h"
+   #define sdlmixerheader "SDL_mixer.h"
    #include sdlheader
   #endif 
 
@@ -84,7 +84,7 @@
   #endif
 
   #define CASE_SENSITIVE_FILE_NAMES 1
-  #define USE_HOME_DIRECTORY 1
+  #define USE_HOME_DIRECTORY 0
 
 
 #endif

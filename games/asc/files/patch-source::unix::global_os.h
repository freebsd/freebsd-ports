
$FreeBSD$

--- source/unix/global_os.h	2001/05/22 19:32:32	1.1
+++ source/unix/global_os.h	2001/05/22 19:33:06
@@ -43,7 +43,7 @@
  #define global_os_h_included
 
   #ifndef minimalIO
-   #define sdlheader "SDL/SDL.h"
+   #define sdlheader "SDL.h"
    #include sdlheader
   #endif 
 
@@ -60,7 +60,7 @@
   #endif
 
   #define CASE_SENSITIVE_FILE_NAMES 1
-  #define USE_HOME_DIRECTORY 1
+  #define USE_HOME_DIRECTORY 0
 
 
 #endif

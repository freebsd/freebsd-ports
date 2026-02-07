--- src/platform_linux.cc.orig	2019-09-28 21:11:07 UTC
+++ src/platform_linux.cc
@@ -1,6 +1,8 @@
 // Copyright (c) 2015 Sergio Gonzalez. All rights reserved.
 // License: https://github.com/serge-rgb/milton#license
 
+#include <SDL_image.h>
+
 #include "platform.h"
 
 #include "common.h"
@@ -30,7 +32,7 @@ perf_counter()
         milton_log("Something went wrong with clock_gettime\n");
     }
 
-    return tp.tv_nsec;
+    return tp.tv_sec * 1000 * 1000 * 1000 + tp.tv_nsec;
 }
 
 void
@@ -357,7 +359,14 @@ platform_deinit(PlatformState* platform)
 void
 platform_setup_cursor(Arena* arena, PlatformState* platform)
 {
+    SDL_Surface *surface;
 
+    surface = IMG_Load("milton.png");
+    if (surface == NULL)
+        return;
+
+    SDL_SetWindowIcon(platform->window, surface);
+    SDL_FreeSurface(surface);
 }
 
 v2i

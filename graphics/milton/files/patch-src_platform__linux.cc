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
@@ -148,7 +150,7 @@ platform_dialog_yesno(char* info, char* title)
 }
 
 YesNoCancelAnswer
-platform_dialog_yesnocancel(char* info, char* title);
+platform_dialog_yesnocancel(char* info, char* title)
 {
     // NOTE: As of 2019-09-23, this function hasn't been tested on Linux.
 
@@ -342,5 +344,32 @@ platform_deinit(PlatformState* platform)
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
+}
+
+v2i
+platform_cursor_get_position(PlatformState* platform)
+{
+    v2i pos;
+
+    SDL_GetMouseState(&pos.x, &pos.y);
+    return pos;
+}
+
+void
+platform_cursor_set_position(PlatformState* platform, v2i pos)
+{
+    SDL_WarpMouseInWindow(platform->window, pos.x, pos.y);
+
+    // Pending mouse move events will have the cursor close
+    // to where it was before we set it.
+    SDL_FlushEvent(SDL_MOUSEMOTION);
+    SDL_FlushEvent(SDL_SYSWMEVENT);
 }

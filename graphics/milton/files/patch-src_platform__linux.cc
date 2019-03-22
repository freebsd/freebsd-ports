--- src/platform_linux.cc.orig	2019-03-15 04:11:43 UTC
+++ src/platform_linux.cc
@@ -1,6 +1,8 @@
 // Copyright (c) 2015 Sergio Gonzalez. All rights reserved.
 // License: https://github.com/serge-rgb/milton#license
 
+#include <SDL_image.h>
+
 #include "platform.h"
 
 #include "common.h"
@@ -318,5 +320,12 @@ platform_deinit(PlatformState* platform)
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

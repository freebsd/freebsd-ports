--- src/sdl.c.orig	2023-10-11 15:50:11 UTC
+++ src/sdl.c
@@ -42,6 +42,10 @@ void sdl_init(int width, int height, bool fullscreen) 
     fprintf(stderr, "Could not initialize SDL - %s\n", SDL_GetError());
     exit(1);
   }
+  if(!SDL_SetHint(SDL_HINT_GRAB_KEYBOARD,"1"))
+    printf("Override SDL_HINT_GRAB_KEYBOARD to 1 failed.\n");
+  if(!SDL_SetHint(SDL_HINT_ALLOW_ALT_TAB_WHILE_GRABBED,"0"))
+    printf("Override SDL_HINT_ALLOW_ALT_TAB_WHILE_GRABBED to 0 failed.\n");
 
   fullscreen_flags = fullscreen?SDL_WINDOW_FULLSCREEN:0;
   window = SDL_CreateWindow("Moonlight", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | fullscreen_flags);
@@ -72,8 +76,19 @@ void sdl_init(int width, int height, bool fullscreen) 
 void sdl_loop() {
   SDL_Event event;
 
+  iskeyboardgrab = true;
   SDL_SetRelativeMouseMode(SDL_TRUE);
+#if SDL_VERSION_ATLEAST(2, 0, 15)
+  // On SDL 2.0.15+, we can get keyboard-only grab on Win32, X11, and Wayland.
+  // SDL 2.0.18 adds keyboard grab on macOS (if built with non-AppStore APIs).
+  SDL_SetWindowKeyboardGrab(window, SDL_TRUE);
+  if(!SDL_GetWindowKeyboardGrab(window))
+    printf("Try to grab window failed.\n");
+#else
+  SDL_SetWindowGrab(window, SDL_TRUE);
+#endif
 
+
   while(!done && SDL_WaitEvent(&event)) {
     switch (sdlinput_handle_event(window, &event)) {
     case SDL_QUIT_APPLICATION:
@@ -90,6 +105,30 @@ void sdl_loop() {
     case SDL_MOUSE_UNGRAB:
       SDL_SetRelativeMouseMode(SDL_FALSE);
       SDL_ShowCursor(SDL_DISABLE);
+      break;
+    case SDL_WINDOW_GRAB:
+      if(!SDL_SetHintWithPriority(SDL_HINT_ALLOW_ALT_TAB_WHILE_GRABBED,"0",SDL_HINT_OVERRIDE))
+        printf("Override SDL_HINT_ALLOW_ALT_TAB_WHILE_GRABBED to 0 failed.\n");
+      SDL_ShowCursor(SDL_ENABLE);
+      SDL_SetRelativeMouseMode(SDL_TRUE);
+      iskeyboardgrab = true;
+#if SDL_VERSION_ATLEAST(2, 0, 15)
+      SDL_SetWindowKeyboardGrab(window, SDL_TRUE);
+#else
+      SDL_SetWindowGrab(window, SDL_TRUE);
+#endif
+      break;
+    case SDL_WINDOW_UNGRAB:
+      if(!SDL_SetHintWithPriority(SDL_HINT_ALLOW_ALT_TAB_WHILE_GRABBED,"1",SDL_HINT_OVERRIDE))
+        printf("Override SDL_HINT_ALLOW_ALT_TAB_WHILE_GRABBED to 1 failed.\n");
+      SDL_SetRelativeMouseMode(SDL_FALSE);
+      SDL_ShowCursor(SDL_DISABLE);
+      iskeyboardgrab = false;
+#if SDL_VERSION_ATLEAST(2, 0, 15)
+      SDL_SetWindowKeyboardGrab(window, SDL_FALSE);
+#else
+      SDL_SetWindowGrab(window, SDL_FALSE);
+#endif
       break;
     default:
       if (event.type == SDL_QUIT)

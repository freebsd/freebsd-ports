--- src/sdl.h.orig	2023-10-11 15:50:11 UTC
+++ src/sdl.h
@@ -28,6 +28,8 @@
 #define SDL_MOUSE_GRAB 2
 #define SDL_MOUSE_UNGRAB 3
 #define SDL_TOGGLE_FULLSCREEN 4
+#define SDL_WINDOW_GRAB 5
+#define SDL_WINDOW_UNGRAB 6
 
 #define SDL_CODE_FRAME 0
 
@@ -36,6 +38,7 @@
 void sdl_init(int width, int height, bool fullscreen);
 void sdl_loop();
 
+extern bool iskeyboardgrab;
 extern SDL_mutex *mutex;
 extern int sdlCurrentFrame, sdlNextFrame;
 

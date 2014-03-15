--- ./src/SDLWindow.cpp.orig	2013-12-21 13:18:27.000000000 +0100
+++ ./src/SDLWindow.cpp	2014-03-15 19:52:52.290284158 +0100
@@ -406,5 +406,5 @@
 // Construct and initialise an OpenGL SDL window
 IWindowPtr make_sdl_window()
 {
-   return shared_ptr<IWindow>(new SDLWindow);
+   return shared_ptr<IWindow>(static_cast<IWindow *>(new SDLWindow));
 }

https://bugzilla.libsdl.org/show_bug.cgi?id=3692
https://hg.libsdl.org/SDL/rev/97c66d81b2c9

--- src/video/x11/SDL_x11window.c.orig	2016-10-20 03:56:26 UTC
+++ src/video/x11/SDL_x11window.c
@@ -376,7 +376,7 @@ X11_CreateWindow(_THIS, SDL_Window * window)
     Atom _NET_WM_WINDOW_TYPE;
     Atom wintype;
     const char *wintype_name = NULL;
-    int compositor = 1;
+    long compositor = 1;
     Atom _NET_WM_PID;
     Atom XdndAware, xdnd_version = 5;
     long fevent = 0;

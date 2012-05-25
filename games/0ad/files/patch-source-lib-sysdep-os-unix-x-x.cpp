--- source/lib/sysdep/os/unix/x/x.cpp.orig	2012-05-18 13:26:07.715192771 +0200
+++ source/lib/sysdep/os/unix/x/x.cpp	2012-05-18 13:26:35.139193906 +0200
@@ -40,10 +40,10 @@
 
 #define Cursor X__Cursor
 
-#include <Xlib.h>
+#include <X11/Xlib.h>
 #include <stdlib.h>
-#include <Xatom.h>
-#include <Xcursor/Xcursor.h>
+#include <X11/Xatom.h>
+#include <X11/Xcursor/Xcursor.h>
 
 #include "SDL.h"
 #include "SDL_syswm.h"

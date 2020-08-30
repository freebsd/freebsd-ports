--- toon.h.orig	2008-02-25 16:41:19 UTC
+++ toon.h
@@ -1,6 +1,6 @@
 #include <X11/Xlib.h>
 
 #define TOON_MESSAGE_LENGTH 128
-char toon_message[TOON_MESSAGE_LENGTH];
+/* char toon_message[TOON_MESSAGE_LENGTH]; */
 
 Window ToonGetRootWindow(Display *display, int screen, Window *clientparent);

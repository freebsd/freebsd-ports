--- x11/ui.h.orig	2012-05-27 06:52:31.000000000 +0900
+++ x11/ui.h	2012-05-27 06:52:59.000000000 +0900
@@ -338,7 +338,7 @@
 
 
   // Variables.
-  static char *keysNames[UI_KEYS_MAX];
+  static const char *keysNames[UI_KEYS_MAX];
 
   char **argv;  // Warning: Exposing the rep.
   int argc;
@@ -402,7 +402,7 @@
   // The callbacks to export to the Viewport.
   static ViewportCallback viewportCallbacks[VIEWPORT_CB_NUM];
 
-  static char* helpMessage;
+  static const char* helpMessage;
 };
 
 #endif

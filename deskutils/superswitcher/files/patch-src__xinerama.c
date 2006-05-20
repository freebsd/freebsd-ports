#
# Fix build on 4.x
#
--- ./src/xinerama.c.orig	Sat May 20 18:36:30 2006
+++ ./src/xinerama.c	Sat May 20 18:38:45 2006
@@ -22,24 +22,26 @@
   int minimum_width;
   SSXineramaScreen *screens;
   SSXinerama *xinerama;
-
-  minimum_width = 0;
+  int x_screen;
 
 #ifdef HAVE_XINERAMA
   gboolean xinerama_is_active = XineramaIsActive (x_display);
+  XineramaScreenInfo *xsi_array;
+  XineramaScreenInfo *xsi;
 #else
   gboolean xinerama_is_active = FALSE;
 #endif
 
+  minimum_width = 0;
+
   if (xinerama_is_active) {
 #ifdef HAVE_XINERAMA
-    XineramaScreenInfo *xsi_array =
-      XineramaQueryScreens(x_display, &num_screens);
+    xsi_array = XineramaQueryScreens(x_display, &num_screens);
     screens = g_new (SSXineramaScreen, num_screens);
 
     int i;
     for (i = 0; i < num_screens; i++) {
-      XineramaScreenInfo *xsi = &xsi_array[i];
+      xsi = &xsi_array[i];
       screens[i].x = xsi->x_org;
       screens[i].y = xsi->y_org;
       screens[i].width  = xsi->width;
@@ -54,7 +56,7 @@
 #endif
   } else {
     num_screens = 1;
-    int x_screen = DefaultScreen (x_display);
+    x_screen = DefaultScreen (x_display);
     screens = g_new (SSXineramaScreen, num_screens);
     screens[0].x = 0;
     screens[0].y = 0;

--- modules/graphics/src/main/native-glass/gtk/glass_window.h.orig	2017-09-08 16:56:55 UTC
+++ modules/graphics/src/main/native-glass/gtk/glass_window.h
@@ -365,7 +365,7 @@ class WindowContextChild: public WindowContextBase { (
 class WindowContextTop: public WindowContextBase {
     jlong screen;
     WindowFrameType frame_type;
-    struct WindowContext *owner;
+    WindowContext *owner;
     WindowGeometry geometry;
     int stale_config_notifications;
     struct _Resizable{// we can't use set/get gtk_window_resizable function
@@ -455,4 +455,3 @@ class EventsCounterHelper { (public)
 };
 
 #endif        /* GLASS_WINDOW_H */
-

--- modules/javafx.graphics/src/main/native-glass/gtk/glass_window.h.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.graphics/src/main/native-glass/gtk/glass_window.h
@@ -366,7 +366,7 @@ class WindowContextTop: public WindowContextBase {
     jlong screen;
     WindowFrameType frame_type;
     WindowType window_type;
-    struct WindowContext *owner;
+    WindowContext *owner;
     WindowGeometry geometry;
     struct _Resizable{// we can't use set/get gtk_window_resizable function
         _Resizable(): request(REQUEST_NONE), value(true), prev(false),
@@ -472,4 +472,3 @@ class EventsCounterHelper { (public)
 };
 
 #endif        /* GLASS_WINDOW_H */
-

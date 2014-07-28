--- UI/BasicWidget.hxx.orig	Sat Dec 21 01:48:54 2002
+++ UI/BasicWidget.hxx	Sat Dec 21 01:48:57 2002
@@ -54,10 +54,10 @@
         int x, int y, int width, int height);
 
     // UIApplication needs access to the handleEvent and findWidget methods
-    friend UIApplication;
+    friend class UIApplication;
 
     // ContainerWidget needs access to the findWidget method
-    friend ContainerWidget;
+    friend class ContainerWidget;
 
     // Called whenever an event arrives for me
     virtual void handleEvent(XEvent* event);

--- src/drawing_area.h.orig	2007-11-21 17:48:25.000000000 +0100
+++ src/drawing_area.h	2007-11-21 17:48:50.000000000 +0100
@@ -156,7 +156,7 @@
      * 
      * @return drawing_area which has the same dimensions and location as r.
      */
-    drawing_area& drawing_area::operator = (SDL_Rect& r); 
+    drawing_area& operator = (SDL_Rect& r); 
 #endif
     
     /** 

--- src/Scope.cc.orig	2018-01-19 00:47:02 UTC
+++ src/Scope.cc
@@ -132,7 +132,7 @@ Scope::resize (bool redraw)
     clearbuffer ();
 
     if (redraw) {
-	XRectangle rect = { 0, 0, width, height };
+	XRectangle rect = { 0, 0, static_cast<unsigned short>(width), static_cast<unsigned short>(height) };
 	draw (rect);
     }
 }
@@ -193,7 +193,7 @@ Scope::clear (bool drawit)
     clearbuffer ();
 
     if (drawit) {
-	XRectangle rect = { 0, 0, width, height };
+	XRectangle rect = { 0, 0, static_cast<unsigned short>(width), static_cast<unsigned short>(height) };
 	draw (rect);
     }
 }
@@ -310,7 +310,7 @@ Scope::shot (const int32_t* buffer, bool drawit)
     }
 
     if (drawit && sample.frame_count % num_count == num_count - 1) {
-	XRectangle rect = { 0, 0, width, height };
+	XRectangle rect = { 0, 0, static_cast<unsigned short>(width), static_cast<unsigned short>(height) };
 	draw (rect);
     }
 

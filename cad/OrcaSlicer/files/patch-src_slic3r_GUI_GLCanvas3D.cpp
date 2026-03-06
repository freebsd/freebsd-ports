--- src/slic3r/GUI/GLCanvas3D.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/GLCanvas3D.cpp
@@ -109,7 +109,7 @@ float RetinaHelper::get_scale_factor() { return float(
 #endif // __WXGTK3__
 
 // Fixed the collision between BuildVolume_Type::Convex and macro Convex defined inside /usr/include/X11/X.h that is included by WxWidgets 3.0.
-#if defined(__linux__) && defined(Convex)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(Convex)
 #undef Convex
 #endif
 
@@ -1839,7 +1839,11 @@ void GLCanvas3D::render(bool only_init)
         return;
 
     // ensures this canvas is current and initialized
-    if (!_is_shown_on_screen() || !_set_current() || !wxGetApp().init_opengl())
+    if (!_is_shown_on_screen())
+        return;
+    if (!_set_current())
+        return;
+    if (!wxGetApp().init_opengl())
         return;
 
     if (!is_initialized() && !init())

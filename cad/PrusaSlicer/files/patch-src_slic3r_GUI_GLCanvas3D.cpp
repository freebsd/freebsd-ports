--- src/slic3r/GUI/GLCanvas3D.cpp.orig	2024-06-27 09:25:47 UTC
+++ src/slic3r/GUI/GLCanvas3D.cpp
@@ -104,7 +104,7 @@ float RetinaHelper::get_scale_factor() { return float(
 #endif // __WXGTK3__
 
 // Fixed the collision between BuildVolume::Type::Convex and macro Convex defined inside /usr/include/X11/X.h that is included by WxWidgets 3.0.
-#if defined(__linux__) && defined(Convex)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(Convex)
 #undef Convex
 #endif
 

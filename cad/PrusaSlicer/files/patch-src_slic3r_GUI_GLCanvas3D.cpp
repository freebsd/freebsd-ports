--- src/slic3r/GUI/GLCanvas3D.cpp.orig	2023-07-25 09:31:07 UTC
+++ src/slic3r/GUI/GLCanvas3D.cpp
@@ -97,7 +97,7 @@ float RetinaHelper::get_scale_factor() { return float(
 #endif // __WXGTK3__
 
 // Fixed the collision between BuildVolume::Type::Convex and macro Convex defined inside /usr/include/X11/X.h that is included by WxWidgets 3.0.
-#if defined(__linux__) && defined(Convex)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(Convex)
 #undef Convex
 #endif
 

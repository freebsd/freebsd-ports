--- src/slic3r/GUI/BitmapCache.cpp.orig	2023-12-12 14:21:21 UTC
+++ src/slic3r/GUI/BitmapCache.cpp
@@ -20,8 +20,9 @@
     #include <wx/rawbmp.h>
 #endif /* __WXGTK2__ */
 
-#include <nanosvg/nanosvg.h>
-#include <nanosvg/nanosvgrast.h>
+#include <wx/display.h>
+#include "libnanosvg/nanosvg.h"
+#include "libnanosvg/nanosvgrast.h"
 
 namespace Slic3r { namespace GUI {
 
@@ -73,7 +74,7 @@ wxBitmapBundle* BitmapCache::insert_bndl(const std::st
     wxVector<wxBitmap> bitmaps;
 
     std::set<double> scales = {1.0};
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 #ifdef __APPLE__
     scales.emplace(m_scale);
@@ -554,7 +555,7 @@ wxBitmapBundle BitmapCache::mksolid(size_t width_in, s
     wxVector<wxBitmap> bitmaps;
 
     std::set<double> scales = { 1.0 };
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
 
 #ifdef __APPLE__
     scales.emplace(m_scale);

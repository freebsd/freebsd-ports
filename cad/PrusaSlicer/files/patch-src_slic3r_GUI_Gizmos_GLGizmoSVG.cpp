--- src/slic3r/GUI/Gizmos/GLGizmoSVG.cpp.orig	2024-06-27 09:25:47 UTC
+++ src/slic3r/GUI/Gizmos/GLGizmoSVG.cpp
@@ -23,7 +23,7 @@
 #include "libslic3r/ClipperUtils.hpp" // union_ex
 
 #include "imgui/imgui_stdlib.h" // using std::string for inputs
-#include "nanosvg/nanosvg.h"    // load SVG file
+#include "libnanosvg/nanosvg.h"    // load SVG file
 
 #include <wx/display.h> // detection of change DPI
 #include <boost/log/trivial.hpp>
@@ -587,7 +587,7 @@ void GLGizmoSVG::on_dragging(const UpdateData &data) {
 void GLGizmoSVG::on_dragging(const UpdateData &data) { m_rotate_gizmo.dragging(data); }
 
 #include "slic3r/GUI/BitmapCache.hpp"
-#include "nanosvg/nanosvgrast.h"
+#include "libnanosvg/nanosvgrast.h"
 #include "libslic3r/AABBTreeLines.hpp" // aabb lines for draw filled expolygon
 
 namespace{

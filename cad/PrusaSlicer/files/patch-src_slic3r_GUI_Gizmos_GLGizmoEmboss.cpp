--- src/slic3r/GUI/Gizmos/GLGizmoEmboss.cpp.orig	2023-07-25 16:07:22 UTC
+++ src/slic3r/GUI/Gizmos/GLGizmoEmboss.cpp
@@ -29,7 +29,7 @@
 #include "libslic3r/BuildVolume.hpp"
 
 #include "imgui/imgui_stdlib.h" // using std::string for inputs
-#include "nanosvg/nanosvg.h"    // load SVG file
+#include "libnanosvg/nanosvg.h"    // load SVG file
 
 #include <wx/font.h>
 #include <wx/fontutil.h>

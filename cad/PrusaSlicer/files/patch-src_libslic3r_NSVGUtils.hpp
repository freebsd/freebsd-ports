--- src/libslic3r/NSVGUtils.hpp.orig	2023-12-12 14:21:21 UTC
+++ src/libslic3r/NSVGUtils.hpp
@@ -11,7 +11,7 @@
 #include "Polygon.hpp"
 #include "ExPolygon.hpp"
 #include "EmbossShape.hpp" // ExPolygonsWithIds
-#include "nanosvg/nanosvg.h"    // load SVG file
+#include "libnanosvg/nanosvg.h"    // load SVG file
 
 // Helper function to work with nano svg
 namespace Slic3r {

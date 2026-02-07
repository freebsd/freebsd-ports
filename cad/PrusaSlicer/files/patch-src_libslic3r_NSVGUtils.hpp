--- src/libslic3r/NSVGUtils.hpp.orig	2024-09-18 13:39:04 UTC
+++ src/libslic3r/NSVGUtils.hpp
@@ -15,7 +15,7 @@
 #include "Polygon.hpp"
 #include "ExPolygon.hpp"
 #include "EmbossShape.hpp" // ExPolygonsWithIds
-#include "nanosvg/nanosvg.h"    // load SVG file
+#include <libnanosvg/nanosvg.h>
 #include "libslic3r/Point.hpp"
 #include "libslic3r/libslic3r.h"
 

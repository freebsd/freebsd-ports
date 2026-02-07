--- tests/libslic3r/test_emboss.cpp.orig	2024-12-20 11:54:34 UTC
+++ tests/libslic3r/test_emboss.cpp
@@ -197,7 +197,7 @@ TEST_CASE("Visualize glyph from font", "[Emboss]")
 #endif // VISUALIZE
 
 #include "test_utils.hpp"
-#include <nanosvg/nanosvg.h>    // load SVG file
+#include <libnanosvg/nanosvg.h>    // load SVG file
 #include <libslic3r/NSVGUtils.hpp>
 #include <libslic3r/IntersectionPoints.hpp>
 ExPolygons heal_and_check(const Polygons &polygons)

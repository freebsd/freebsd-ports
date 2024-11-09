--- tests/libslic3r/test_emboss.cpp.orig	2024-09-18 13:39:04 UTC
+++ tests/libslic3r/test_emboss.cpp
@@ -196,7 +196,7 @@ TEST_CASE("Visualize glyph from font", "[Emboss]")
 #endif // VISUALIZE
 
 #include "test_utils.hpp"
-#include <nanosvg/nanosvg.h>    // load SVG file
+#include <libnanosvg/nanosvg.h>    // load SVG file
 #include <libslic3r/NSVGUtils.hpp>
 #include <libslic3r/IntersectionPoints.hpp>
 ExPolygons heal_and_check(const Polygons &polygons)

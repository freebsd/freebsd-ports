--- src/libslic3r/EmbossShape.hpp.orig	2024-09-18 13:39:04 UTC
+++ src/libslic3r/EmbossShape.hpp
@@ -12,7 +12,7 @@
 #include "Point.hpp" // Transform3d
 #include "ExPolygon.hpp"
 #include "ExPolygonSerialize.hpp"
-#include "nanosvg/nanosvg.h" // NSVGimage
+#include <libnanosvg/nanosvg.h> // NSVGimage
 
 namespace Slic3r {
 

--- src/libslic3r/EmbossShape.hpp.orig	2024-01-12 13:37:33 UTC
+++ src/libslic3r/EmbossShape.hpp
@@ -12,7 +12,7 @@
 #include "Point.hpp" // Transform3d
 #include "ExPolygon.hpp"
 #include "ExPolygonSerialize.hpp"
-#include "nanosvg/nanosvg.h" // NSVGimage
+#include "libnanosvg/nanosvg.h" // NSVGimage
 
 namespace Slic3r {
 

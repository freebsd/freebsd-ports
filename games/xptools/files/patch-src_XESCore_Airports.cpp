/usr/local/include/boost/numeric/interval/hw_rounding.hpp:42:4: error: Boost.Numeric.Interval: Please specify rounding control mechanism.
--- src/XESCore/Airports.cpp.orig	2017-11-07 03:31:14 UTC
+++ src/XESCore/Airports.cpp
@@ -38,6 +38,10 @@
 #include "CompGeomUtils.h"
 #include "MapBuffer.h"
 #include <CGAL/convex_hull_2.h>
+// FIXME Arch-specific!
+#define __x86_64__ YES
+#define __USE_ISOC99 YES
+// END FIXME
 #include <CGAL/Sweep_line_2_algorithms.h>
 #include <CGAL/Boolean_set_operations_2/Gps_polygon_validation.h>
 #if DEV

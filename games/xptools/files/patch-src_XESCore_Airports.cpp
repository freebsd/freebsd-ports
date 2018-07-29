/usr/local/include/boost/numeric/interval/hw_rounding.hpp:42:4: error: Boost.Numeric.Interval: Please specify rounding control mechanism.
--- src/XESCore/Airports.cpp.orig	2018-07-05 08:14:27 UTC
+++ src/XESCore/Airports.cpp
@@ -38,6 +38,12 @@
 #include "CompGeomUtils.h"
 #include "MapBuffer.h"
 #include <CGAL/convex_hull_2.h>
+// FIXME Arch-specific!
+#ifndef __x86_64__
+#define __x86_64__ YES
+#endif
+#define __USE_ISOC99 YES
+// END FIXME
 #include <CGAL/Sweep_line_2_algorithms.h>
 #include <CGAL/Boolean_set_operations_2/Gps_polygon_validation.h>
 #if DEV

--- lib/IlmCtlMath/CtlPointTree.h.orig	2014-06-03 01:11:24 UTC
+++ lib/IlmCtlMath/CtlPointTree.h
@@ -71,6 +71,8 @@
 #include <vector>
 #include <algorithm>
 
+#include <limits>
+
 namespace Ctl {
 
 class PointTree
@@ -181,7 +183,7 @@ class PointTree
 	    double bl = (_points[b] - _center).length2();
 
 	    volatile double delta = fabs (al - bl);
-	    const double eps = 2.0 * Imath::limits<double>::epsilon();
+	    const double eps = 2.0 * std::numeric_limits<double>::epsilon();
 
     	    //
 	    // Impose strict weak ordering... if the lengths are the same,

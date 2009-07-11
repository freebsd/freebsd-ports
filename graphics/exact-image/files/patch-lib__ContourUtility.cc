--- lib/ContourUtility.cc.orig	2009-07-10 10:25:43.000000000 -0400
+++ lib/ContourUtility.cc	2009-07-10 10:26:31.000000000 -0400
@@ -1,9 +1,9 @@
-#include "ContourUtility.hh"
 #include <cmath>
 #include <cstdlib>
 //#include <iostream>
 #include <assert.h>
 #include <stdio.h>
+#include "ContourUtility.hh"
 
 void CenterAndReduce(const Contours::Contour& source,
 		     Contours::Contour& dest,

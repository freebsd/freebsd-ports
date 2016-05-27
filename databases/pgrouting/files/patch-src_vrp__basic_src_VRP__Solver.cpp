--- src/vrp_basic/src/VRP_Solver.cpp.orig	2016-05-16 20:28:00 UTC
+++ src/vrp_basic/src/VRP_Solver.cpp
@@ -28,6 +28,8 @@ Foundation, Inc., 51 Franklin Street, Fi
 
 #include <algorithm>
 #include "VRP_Solver.h"
+#include <cstdlib>
+#include <cmath>
 
 #undef PGR_LOGGER_ON
 #define PGR_LOGGER_LOC

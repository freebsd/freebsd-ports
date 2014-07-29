--- cmn/world.cpp.orig	2012-05-27 06:52:30.000000000 +0900
+++ cmn/world.cpp	2012-05-27 06:53:11.000000000 +0900
@@ -35,7 +35,7 @@
 #endif
 
 // Include Files.
-#include <iostream.h>
+#include <iostream>
 
 #include "utils.h"
 #include "coord.h"
@@ -48,6 +48,7 @@
 // For PhysMover.
 #include "actual.h"
 
+using namespace std;
 
 // Defines.
 #define HANGING_PERCENT 0.40 // The % of the edge hanging off the corner.

--- ./src/WorkArea/CAEH_grid.cpp.orig	Mon Jul 21 16:34:35 2003
+++ ./src/WorkArea/CAEH_grid.cpp	Mon Jul 21 16:34:54 2003
@@ -8,7 +8,7 @@
 #include "CAEH_grid.h"
 
 #include <strstream>
-
+using std::ostrstream;
 
 
 CAEH_grid::CAEH_grid(CadArea *c, const CGrid& gr)

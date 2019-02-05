--- include/dsrpdb/Point.h.orig	2019-02-05 18:18:53 UTC
+++ include/dsrpdb/Point.h
@@ -22,6 +22,7 @@ MA 02111-1307, USA. */
 #define DSR_PDB_POINT_H
 #include <iostream>
 #include <dsrpdb/config.h>
+#include <assert.h>
 
 #ifdef PDB_USE_CGAL 
 #include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

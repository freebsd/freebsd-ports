--- ./src/modules/simu/simuv2/SOLID-2.0/src/C-api.cpp.orig	Sat Apr 19 11:46:43 2003
+++ ./src/modules/simu/simuv2/SOLID-2.0/src/C-api.cpp	Sat May 10 00:19:56 2003
@@ -40,6 +40,7 @@
 #include "Polyhedron.h"
 #include "Response.h"
 #include "RespTable.h"
+#include <sys/types.h>
 
 #include <map>
 #include <set>

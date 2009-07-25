--- Geo/GModelIO_CGNS.cpp-xxx	2009-07-20 16:54:23.000000000 -0500
+++ Geo/GModelIO_CGNS.cpp	2009-07-20 16:55:01.000000000 -0500
@@ -24,6 +24,7 @@
 #define omp_destroy_lock(x)
 #endif
 
+#include <cstdio>
 #include <cstring>
 #include <iostream>  // DBG
 #include <map>

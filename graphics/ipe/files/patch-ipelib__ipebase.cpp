--- ipelib/ipebase.cpp.orig
+++ ipelib/ipebase.cpp
@@ -29,7 +29,9 @@
 */
 
 #include "ipebase.h"
+#include <cstdlib>
 #include <cmath>
+#include <sys/types.h>
 
 using namespace ipe;
 

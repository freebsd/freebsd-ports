--- backend/src/backend/gen_reg_allocation.cpp.orig	2015-01-30 00:57:16.930955286 +0100
+++ backend/src/backend/gen_reg_allocation.cpp	2015-01-30 00:57:53.886912927 +0100
@@ -33,6 +33,7 @@
 #include <climits>
 #include <iostream>
 #include <iomanip>
+#include <sys/types.h>
 
 
 namespace gbe

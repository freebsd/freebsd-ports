--- backend/src/backend/gen_reg_allocation.cpp.orig	2017-01-20 10:40:51 UTC
+++ backend/src/backend/gen_reg_allocation.cpp
@@ -33,6 +33,7 @@
 #include <climits>
 #include <iostream>
 #include <iomanip>
+#include <sys/types.h>
 
 
 #define HALF_REGISTER_FILE_OFFSET (32*64)

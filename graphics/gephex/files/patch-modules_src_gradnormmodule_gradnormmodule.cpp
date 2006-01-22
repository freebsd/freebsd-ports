--- modules/src/gradnormmodule/gradnormmodule.cpp.orig
+++ modules/src/gradnormmodule/gradnormmodule.cpp
@@ -29,7 +29,7 @@
 
 #if !defined(_MSC_VER) || (_MSC_VER > 1200)
 using std::min;
-#include <stdint.h>
+#include <inttypes.h>
 #else
 #define min(a, b) ((a) < (b) ? (a) : (b))
 #include "basic_types.h"

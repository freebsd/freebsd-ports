This patch is needed in order to make the port build with a gcc newer than the one in base.

FILE* is used in preprocessor.cpp, so a suitable declaration is needed.

--- generator/parser/rpp/preprocessor.cpp
+++ generator/parser/rpp/preprocessor.cpp
@@ -41,6 +41,7 @@
 
 #include "preprocessor.h"
 
+#include <cstdio>
 #include <string>
 
 // register callback for include hooks

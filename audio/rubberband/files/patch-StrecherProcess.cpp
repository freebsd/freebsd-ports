--- src/StretcherProcess.cpp-dist	2012-01-08 17:24:27.535146749 +0100
+++ src/StretcherProcess.cpp	2012-01-08 17:21:19.739152441 +0100
@@ -26,7 +26,8 @@
 #include "system/VectorOps.h"
 
 #ifndef _WIN32
-#include <alloca.h>
+/* linux stdlib include alloca.h */
+#include <stdlib.h>
 #endif
 
 #include <cassert>

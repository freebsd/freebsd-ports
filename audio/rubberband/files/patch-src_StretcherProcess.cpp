--- src/StretcherProcess.cpp.orig	2012-10-28 10:30:09 UTC
+++ src/StretcherProcess.cpp
@@ -35,7 +35,8 @@
 #include "system/VectorOps.h"
 
 #ifndef _WIN32
-#include <alloca.h>
+/* linux stdlib include alloca.h */
+#include <stdlib.h>
 #endif
 
 #include <cassert>

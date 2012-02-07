--- src/StretcherImpl.cpp-dist	2012-01-08 17:23:26.816147081 +0100
+++ src/StretcherImpl.cpp	2012-01-08 17:22:19.098146464 +0100
@@ -28,7 +28,7 @@
 #include "base/Profiler.h"
 
 #ifndef _WIN32
-#include <alloca.h>
+#include <stdlib.h>
 #endif
 
 #include <cassert>

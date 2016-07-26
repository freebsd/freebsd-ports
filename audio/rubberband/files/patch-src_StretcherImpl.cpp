--- src/StretcherImpl.cpp.orig	2012-10-28 10:30:09 UTC
+++ src/StretcherImpl.cpp
@@ -38,7 +38,7 @@
 #include "base/Profiler.h"
 
 #ifndef _WIN32
-#include <alloca.h>
+#include <stdlib.h>
 #endif
 
 #include <cassert>

--- simpleperf/dso.cpp.orig	2015-08-12 01:49:40 UTC
+++ simpleperf/dso.cpp
@@ -16,6 +16,7 @@
 
 #include "dso.h"
 
+#include <limits.h> // ULLONG_MAX
 #include <stdlib.h>
 #include <base/logging.h>
 #include "environment.h"

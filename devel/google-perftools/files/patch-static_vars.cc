--- src/static_vars.cc	2014-01-14 17:23:28.000000000 -0800
+++ src/static_vars.cc	2014-01-14 17:28:39.000000000 -0800
@@ -37,6 +37,7 @@
 #include "common.h"
 #include "sampler.h"           // for Sampler
 #include "base/googleinit.h"
+#include <pthread.h>
 
 namespace tcmalloc {
 

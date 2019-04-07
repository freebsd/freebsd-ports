--- src/midilfo.cpp.orig	2019-04-05 09:20:35 UTC
+++ src/midilfo.cpp
@@ -22,6 +22,9 @@
  *
  */
 #include <cmath>
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
 #include "midilfo.h"
 
 

--- base/include/preferences.h.orig	Sat Mar 15 10:01:45 2003
+++ base/include/preferences.h	Mon Aug 18 17:32:11 2003
@@ -26,7 +26,10 @@
 
 #include <string>
 #include <vector>
+#include <inttypes.h>
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 
 #include "config.h"
 #include "errors.h"

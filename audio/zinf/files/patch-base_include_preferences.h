--- base/include/preferences.h.orig	2003-09-16 17:34:53 UTC
+++ base/include/preferences.h
@@ -26,7 +26,10 @@ ________________________________________
 
 #include <string>
 #include <vector>
+#include <inttypes.h>
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 
 #include "config.h"
 #include "errors.h"

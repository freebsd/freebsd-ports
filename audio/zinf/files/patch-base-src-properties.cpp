--- base/src/properties.cpp.orig	Wed Nov 12 04:59:07 2003
+++ base/src/properties.cpp	Mon Feb 16 11:51:23 2004
@@ -29,7 +29,9 @@
 #endif
 
 
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 // #include <map>
 #include <vector>
 #include <string>

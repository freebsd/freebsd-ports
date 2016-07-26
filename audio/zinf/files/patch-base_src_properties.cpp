--- base/src/properties.cpp.orig	2003-11-11 19:59:07 UTC
+++ base/src/properties.cpp
@@ -29,7 +29,9 @@ ________________________________________
 #endif
 
 
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 // #include <map>
 #include <vector>
 #include <string>

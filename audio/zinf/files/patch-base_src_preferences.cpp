--- base/src/preferences.cpp.orig	2004-02-14 00:24:01.000000000 +0200
+++ base/src/preferences.cpp
@@ -31,6 +31,9 @@ ________________________________________
 #include <string>
 #include <stdlib.h>
 
+extern "C" {
+#include <strings.h>
+}
 #ifdef __QNX__
 #include <strings.h>
 #endif

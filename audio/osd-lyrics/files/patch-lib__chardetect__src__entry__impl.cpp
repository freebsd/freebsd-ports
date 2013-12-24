--- lib/chardetect/src/entry/impl.cpp.orig
+++ lib/chardetect/src/entry/impl.cpp
@@ -41,8 +41,10 @@
 #include "chardetect.h"
 #include "nscore.h"
 #include "nsUniversalDetector.h"
+#pragma GCC visibility push(default)
 #include <string.h>
 #include <stdlib.h>
+#pragma GCC visibility pop
 
 #ifdef _WIN32
 #   include <windows.h>

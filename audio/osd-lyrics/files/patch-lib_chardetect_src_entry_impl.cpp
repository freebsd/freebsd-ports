--- lib/chardetect/src/entry/impl.cpp.orig	2012-06-04 03:45:15 UTC
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

--- ./charset-detector/src/entry/impl.cpp.orig	2011-03-22 16:53:02.918217862 -0700
+++ ./charset-detector/src/entry/impl.cpp	2011-03-22 16:53:47.868220433 -0700
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
@@ -53,7 +55,6 @@
 #pragma managed(push, off)
 #endif
 
-
 class DllDetector : public nsUniversalDetector
 {
 protected:

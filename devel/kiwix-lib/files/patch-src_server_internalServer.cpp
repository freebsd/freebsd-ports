--- src/server/internalServer.cpp.orig	2020-12-06 02:30:03 UTC
+++ src/server/internalServer.cpp
@@ -18,6 +18,7 @@
  */
 
 #include "internalServer.h"
+#include <netinet/in.h>
 
 #ifdef _WIN32
 # if !defined(__MINGW32__) && (_MSC_VER < 1600)

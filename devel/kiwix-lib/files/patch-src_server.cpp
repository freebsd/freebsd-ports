--- src/server.cpp.orig	2020-07-18 00:12:50 UTC
+++ src/server.cpp
@@ -18,6 +18,7 @@
  */
 
 #include "server.h"
+#include <netinet/in.h>
 
 #ifdef _WIN32
 # if !defined(__MINGW32__) && (_MSC_VER < 1600)

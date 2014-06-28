--- src/ximim.cpp.orig	2014-06-28 22:13:59.000000000 +0900
+++ src/ximim.cpp	2014-06-28 22:14:31.000000000 +0900
@@ -15,6 +15,7 @@
 #  include <alloca.h>
 # endif
 #endif
+#include <stdlib.h>
 
 static std::map<int,XimIM *> g_ims;
 

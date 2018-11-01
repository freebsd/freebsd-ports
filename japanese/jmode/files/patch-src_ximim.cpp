--- src/ximim.cpp.orig	2003-05-16 16:07:43 UTC
+++ src/ximim.cpp
@@ -15,6 +15,7 @@
 #  include <alloca.h>
 # endif
 #endif
+#include <stdlib.h>
 
 static std::map<int,XimIM *> g_ims;
 

--- src/scim_hangul_imengine.cpp.orig	2012-07-08 11:16:59.000000000 +0000
+++ src/scim_hangul_imengine.cpp
@@ -33,6 +33,7 @@
   #include <config.h>
 #endif
 
+#include <unistd.h>
 #include <cstring>
 #include <scim.h>
 #include "scim_hangul_imengine.h"

--- src/common/Patch.cpp.orig	2010-01-02 21:18:59.624899346 -0500
+++ src/common/Patch.cpp	2010-01-02 21:18:45.448378670 -0500
@@ -4,7 +4,7 @@
 #include <zlib.h>
 
 #include "Patch.h"
-
+#include <sys/param.h>
 
 #ifdef __GNUC__
 #if defined(__APPLE__) || defined (BSD)

--- src/common/Patch.cpp.orig	2016-08-13 15:20:47 UTC
+++ src/common/Patch.cpp
@@ -6,6 +6,7 @@
 #endif
 
 #include "Patch.h"
+#include <sys/param.h>
 
 #ifndef __LIBRETRO__
 

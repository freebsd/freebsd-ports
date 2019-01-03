--- ext_src/cycles/src/util/util_path.cpp.orig	2018-12-22 14:23:19 UTC
+++ ext_src/cycles/src/util/util_path.cpp
@@ -38,6 +38,10 @@
 #  include <shlwapi.h>
 #endif
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#include <sys/sysctl.h>
+#endif
+
 #include "util/util_map.h"
 #include "util/util_windows.h"
 

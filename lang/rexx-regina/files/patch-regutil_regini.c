--- regutil/regini.c.orig	2014-10-30 04:54:43 UTC
+++ regutil/regini.c
@@ -26,6 +26,7 @@
 #endif
 
 #include "regutil.h"
+#include </usr/include/strings.h>
 
 #ifdef _WIN32
 # include <windows.h>

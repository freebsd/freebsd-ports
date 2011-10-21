--- include/dos_inc.h.orig	2010-05-10 13:43:54.000000000 -0400
+++ include/dos_inc.h	2011-10-18 12:05:51.186449095 -0400
@@ -28,6 +28,8 @@
 #include "mem.h"
 #endif
 
+#include <stddef.h>
+
 #ifdef _MSC_VER
 #pragma pack (1)
 #endif

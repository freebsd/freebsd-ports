--- src/wzd_types.h.orig	Thu Jul 14 22:20:41 2005
+++ src/wzd_types.h	Thu Jul 14 22:21:11 2005
@@ -43,6 +43,8 @@
 # include <inttypes.h>
 #endif
 
+#include <netinet/in.h>
+
 /* win32-common definitions */
 #if defined (WIN32)
 

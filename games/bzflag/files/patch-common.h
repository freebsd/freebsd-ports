--- include/common.h.orig	Sun Sep 12 21:37:57 1999
+++ include/common.h	Sat Aug 12 01:17:34 2000
@@ -76,8 +76,10 @@
 
 #if !defined(_WIN32)
 
+#include <sys/param.h>
+#if !defined(BSD)
 #include <values.h>
-#include <sys/types.h>
+#endif
 
 #if defined(__linux) || (defined(__sgi) && !defined(__INTTYPES_MAJOR))
 typedef u_int16_t	uint16_t;

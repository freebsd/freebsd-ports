--- comp.h.orig	Thu Jun 17 08:32:56 2004
+++ comp.h	Thu Jun 17 08:33:04 2004
@@ -19,6 +19,9 @@
  *           From Hewlett Packard Company.
  */
 
+#if __FreeBSD__ < 5
+#include <sys/types.h>
+#endif
 #include <sys/socket.h>
 
 #ifdef __cplusplus

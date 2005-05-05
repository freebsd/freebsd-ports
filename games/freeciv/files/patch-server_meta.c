--- server/meta.c.orig	Thu May  5 22:30:10 2005
+++ server/meta.c	Thu May  5 22:30:28 2005
@@ -21,6 +21,8 @@
 #include <stdlib.h>
 #include <string.h>
 
+#include <sys/types.h>
+
 #ifdef HAVE_NETINET_IN_H
 #include <netinet/in.h>
 #endif

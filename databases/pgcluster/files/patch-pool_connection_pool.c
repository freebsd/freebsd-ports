--- src/pgcluster/pglb/pool_connection_pool.c	9 May 2004 11:21:36 -0000	1.1.1.4
+++ src/pgcluster/pglb/pool_connection_pool.c	13 May 2004 13:57:23 -0000	1.5
@@ -24,6 +24,9 @@
  */
 #include "config.h"
 
+#ifdef HAVE_SYS_TYPES_H
+#include <sys/types.h>
+#endif             
 #include <sys/socket.h>
 #include <sys/un.h>
 #ifdef HAVE_NETINET_TCP_H

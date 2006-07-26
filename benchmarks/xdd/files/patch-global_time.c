--- global_time.c.orig	Mon May 29 04:12:29 2006
+++ global_time.c	Mon May 29 04:16:36 2006
@@ -42,11 +42,15 @@
 #else /* GENERIC_UNIX */
 #include <netdb.h>
 #include <sys/socket.h>
+#if (FreeBSD)
+#include <sys/types.h>
+#include <sys/unistd.h>
+#endif /* (FreeBSD) */
 #include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <arpa/inet.h>
 #endif
-#if (AIX || HPUX || SOLARIS)
+#if (AIX || HPUX || SOLARIS || FreeBSD)
 #include <stdarg.h>
 #endif
 #include "xdd.h"

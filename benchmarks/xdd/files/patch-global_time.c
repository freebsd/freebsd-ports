--- global_time.c.orig	Fri Mar 16 06:52:49 2007
+++ global_time.c	Fri Mar 16 06:53:39 2007
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

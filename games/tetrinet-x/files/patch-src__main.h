--- src/main.h.orig	Thu Dec 24 06:24:50 1998
+++ src/main.h	Thu Jun 17 09:55:28 2004
@@ -24,7 +24,7 @@
 #endif
 #endif           /* but virtually every other OS NEEDS both */
 #include <arpa/inet.h>      /* is this really necessary? */
-#include <varargs.h>
+#include <stdarg.h>
 #include <errno.h>
 #if HAVE_UNISTD_H
 #include <unistd.h>
@@ -296,5 +296,5 @@
 void net_connected(struct net_t *n, char *buf);
 void net_waitingforteam(struct net_t *n, char *buf);
 void init_main(void);
-void lprintf();
-void lvprintf();
\ No newline at end of file
+void lprintf(char *format, ...);
+void lvprintf(int priority, char *format, ...);

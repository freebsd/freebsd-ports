--- ./newlib/libc/sys/psp/netinet/tcp.h.orig	2012-01-25 19:33:12.000000000 +0000
+++ ./newlib/libc/sys/psp/netinet/tcp.h	2012-01-25 19:33:12.000000000 +0000
@@ -0,0 +1,12 @@
+#ifndef __NETINET_TCP_H__
+#define __NETINET_TCP_H__
+
+#include <netinet/in.h>
+
+#define SOL_TCP    IPPROTO_TCP
+
+/* Socket options */
+#define	TCP_NODELAY	0x01	/* don't delay send to coalesce packets */
+#define	TCP_MAXSEG	0x02	/* set maximum segment size */
+
+#endif

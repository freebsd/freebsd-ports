--- nettest_bsd.c	21 Jan 2003 00:26:14 -0000	1.1.1.3
+++ nettest_bsd.c	21 Jan 2003 00:45:17 -0000
@@ -58,6 +58,7 @@
 #include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <netdb.h>
+#include <sys/param.h>
 #else /* WIN32 */
 #include <process.h>
 #include <windows.h>
@@ -68,6 +69,11 @@
 #include "netlib.h"
 #include "netsh.h"
 #include "nettest_bsd.h"
+
+#ifdef	BSD
+#include <sys/time.h>
+#include <arpa/inet.h>
+#endif	/* BSD */
 
 #ifdef HISTOGRAM
 #ifdef __sgi

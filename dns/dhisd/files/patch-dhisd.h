--- dhisd.h.orig	Sun Nov  4 20:50:14 2001
+++ dhisd.h	Sun Nov  4 20:51:05 2001
@@ -47,7 +47,7 @@
 #include<sys/signal.h>
 #include<sys/wait.h>
 #include<syslog.h>
-#include<varargs.h>
+#include<stdarg.h>
 #include<gmp.h>
 
 #define	BOURNE_SHELL		"/bin/sh"
@@ -64,10 +64,10 @@
 #define	CHECK_FAILS	3		/* maximum check fails */
 
 #define	DHISD_PORT	58800
-#define	DHISD_PID	"/etc/dhis/pid/dhisd.pid"
-#define	DHISD_DB	"/etc/dhis/db/dhis.db"
-#define	DHISD_LOG	"/etc/dhis/log/dhisd.log"
-#define	DHISD_SERVICES	"/etc/dhis/db/services.db"
+#define	DHISD_PID	"/var/run/dhisd.pid"
+#define	DHISD_DB	"__PREFIX__/etc/dhis/dhis.db"
+#define	DHISD_LOG	"/var/log/dhisd.log"
+#define	DHISD_SERVICES	"__PREFIX__/etc/dhis/services.db"
 
 #define	MAX_HOSTNAME	64
 #define	MAX_PASS	16

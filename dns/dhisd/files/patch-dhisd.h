--- dhisd.h.orig	Mon Mar 13 18:08:04 2000
+++ dhisd.h	Mon Feb 26 01:03:00 2001
@@ -62,9 +62,9 @@
 
 #define	MX_PORT		58801
 #define	DHISD_PORT	58800
-#define	DHISD_PID	"/etc/dhis/pid/dhisd.pid"
-#define	DHISD_DB	"/etc/dhis/db/dhis.db"
-#define	DHISD_LOG	"/etc/dhis/log/dhisd.log"
+#define	DHISD_PID	"__PREFIX__/pid/dhisd.pid"
+#define	DHISD_DB	"__PREFIX__/db/dhis.db"
+#define	DHISD_LOG	"__PREFIX__/log/dhisd.log"
 
 #define	MAX_HOSTNAME	64
 #define	MAX_PASS	16

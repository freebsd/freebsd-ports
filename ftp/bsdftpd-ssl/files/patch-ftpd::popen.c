diff -urN ftpd/popen.c.ORI ftpd/popen.c
--- ftpd/popen.c.ORI	Mon Dec 17 12:21:41 2001
+++ ftpd/popen.c	Fri Oct 17 02:27:29 2003
@@ -64,7 +64,7 @@
 #include "pathnames.h"
 #include <syslog.h>
 #include <time.h>
-#include <varargs.h>
+#include <stdarg.h>
 #endif
 
 #define	MAXUSRARGS	100

--- src/ftpq.h.orig	Fri Jul 27 16:56:05 2001
+++ src/ftpq.h	Sat Jul 28 09:15:43 2001
@@ -20,6 +20,9 @@
 
 /* includes */
 #include "../config.h"
+#ifdef HAVE_SYS_TYPES_H
+	#include <sys/types.h>
+#endif
 #ifdef HAVE_CTYPE_H
 	#include <ctype.h>
 #endif
@@ -56,15 +59,12 @@
 #ifdef HAVE_SYS_TIME_H
 	#include <sys/time.h>
 #endif
-#ifdef HAVE_SYS_TYPES_H
-	#include <sys/types.h>
-#endif
 #ifdef HAVE_UNISTD_H
 	#include <unistd.h>
 #endif
 
 /* useful defined constants */
-#define SPOOLDIR    "/tmp/ftpq/"   /* must end in /. Check Makefile, too. */
+#define SPOOLDIR    "/var/spool/ftpq/"   /* must end in /. Check Makefile, too. */
 #define HOSTRESP    2048           /* ftp server response buffer, bytes */
 #define BUFSIZE     2048           /* general purpose global buffer */
 #define SMTP_PORT     25

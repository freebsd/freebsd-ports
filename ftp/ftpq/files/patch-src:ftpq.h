--- src/ftpq.h.orig	Tue Sep  4 13:00:00 2001
+++ src/ftpq.h	Wed Sep  5 15:02:03 2001
@@ -35,7 +35,7 @@
 #include <pwd.h>
 
 /* useful defined constants */
-#define SPOOLDIR    "/tmp/ftpq/"   /* must end in /. Check Makefile, too. */
+#define SPOOLDIR    "%%SPOOLDIR%%/"/* must end in /. Check Makefile, too. */
 #define HOSTRESP    2048           /* ftp server response buffer, bytes */
 #define BUFSIZE     2048           /* general purpose global buffer */
 #define SMTP_PORT     25

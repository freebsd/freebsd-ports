--- src/ftp_session.c.orig	Thu Mar 29 00:41:18 2001
+++ src/ftp_session.c	Sat Mar 31 12:07:49 2001
@@ -3,13 +3,13 @@
  */
 
 #include <config.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <string.h>
 #include <stdio.h>
 #include <stdarg.h>
 #include <sys/stat.h>
 #include <unistd.h>
-#include <sys/types.h>
 #include <fcntl.h>
 #include <sys/socket.h>
 #include <errno.h>

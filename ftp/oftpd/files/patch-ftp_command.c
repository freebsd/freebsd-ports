--- src/ftp_command.c.old	Sat Mar 31 11:43:43 2001
+++ src/ftp_command.c	Sat Mar 31 11:44:01 2001
@@ -6,6 +6,7 @@
 #include <string.h>
 #include <ctype.h>
 #include <stdio.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>

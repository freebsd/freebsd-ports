--- ftpq.h.orig	Sun Mar  4 16:00:00 2001
+++ ftpq.h	Wed Mar 21 15:36:15 2001
@@ -22,6 +22,7 @@
 #include <ctype.h>
 #include <dirent.h>
 #include <errno.h>
+#include <sys/types.h>
 #include <netdb.h>
 #include <netinet/in.h>
 #include <pwd.h>
@@ -30,7 +31,6 @@
 #include <string.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
-#include <sys/types.h>
 #include <unistd.h>
 
 /* useful defined constants */

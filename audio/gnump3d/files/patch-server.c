--- src/server.c.orig	Thu May 30 03:58:51 2002
+++ src/server.c	Fri May 31 19:35:18 2002
@@ -32,6 +32,7 @@
  */
 
 
+#include <sys/types.h>
 #include <ctype.h>
 #include <netdb.h>
 #include <pwd.h>

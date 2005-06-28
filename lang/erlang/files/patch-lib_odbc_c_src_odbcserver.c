--- lib/odbc/c_src/odbcserver.c.orig	Sat Jun 25 17:34:20 2005
+++ lib/odbc/c_src/odbcserver.c	Sat Jun 25 17:34:33 2005
@@ -107,6 +107,7 @@
 #include <sys/socket.h>
 #include <sys/uio.h>
 #include <netdb.h>
+#include <netinet/in.h>
 #endif
 
 #include "ei.h"

$FreeBSD$

--- con.h.orig	Fri Oct 25 11:25:17 2002
+++ con.h	Thu Nov  7 15:29:13 2002
@@ -29,8 +29,14 @@
 #include "config.h"
 
 #include <string>
+#include <sys/param.h>
+#include <sys/types.h>
+#include <sys/cdefs.h>
+#include <sys/socket.h>
 #include <netdb.h>
+#include <arpa/inet.h>
 #include <sys/un.h>
+#include <netinet/in.h>
 
 using std::string;
 

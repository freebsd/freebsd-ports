--- sql/mysqld.cc.orig	Tue Dec 14 13:40:36 2004
+++ sql/mysqld.cc	Mon Jan 10 00:28:52 2005
@@ -128,7 +128,7 @@
 #endif /* __WIN__ */
 
 #ifdef HAVE_LIBWRAP
-#include <tcpd.h>
+#include "mytcpd.h"
 #include <syslog.h>
 #ifdef NEED_SYS_SYSLOG_H
 #include <sys/syslog.h>

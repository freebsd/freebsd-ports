--- sql/mysqld.cc.orig	Thu Oct 10 12:17:28 2002
+++ sql/mysqld.cc	Tue Nov 12 23:23:27 2002
@@ -92,7 +92,8 @@
 int allow_severity = LOG_INFO;
 int deny_severity = LOG_WARNING;
 
-#ifdef __STDC__
+#include <osreldate.h>
+#if defined(__STDC__) && __FreeBSD_version < 500000
 #define my_fromhost(A)	   fromhost(A)
 #define my_hosts_access(A) hosts_access(A)
 #define my_eval_client(A)  eval_client(A)

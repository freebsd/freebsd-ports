--- sql/mysqld.cc.orig	Wed Feb  5 01:55:03 2003
+++ sql/mysqld.cc	Wed Feb  5 01:57:06 2003
@@ -104,7 +104,8 @@
 int allow_severity = LOG_INFO;
 int deny_severity = LOG_WARNING;
 
-#ifdef __STDC__
+#include <osreldate.h>
+#if defined(__STDC__) && __FreeBSD_version < 500000
 #define my_fromhost(A)	   fromhost(A)
 #define my_hosts_access(A) hosts_access(A)
 #define my_eval_client(A)  eval_client(A)

--- sql/mysqld.cc.orig	Tue Sep  7 00:29:37 2004
+++ sql/mysqld.cc	Mon Sep 20 08:37:21 2004
@@ -107,15 +107,7 @@
 int allow_severity = LOG_INFO;
 int deny_severity = LOG_WARNING;
 
-#ifdef __STDC__
-#define my_fromhost(A)	   fromhost(A)
-#define my_hosts_access(A) hosts_access(A)
-#define my_eval_client(A)  eval_client(A)
-#else
-#define my_fromhost(A)	   fromhost()
-#define my_hosts_access(A) hosts_access()
-#define my_eval_client(A)  eval_client()
-#endif
+#include "mylibwrap.h"
 #endif /* HAVE_LIBWRAP */
 
 #ifdef HAVE_SYS_MMAN_H

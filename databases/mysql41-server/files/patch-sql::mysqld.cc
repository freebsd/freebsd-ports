--- sql/mysqld.cc.orig	Thu Sep 16 23:47:47 2004
+++ sql/mysqld.cc	Tue Sep 21 23:56:49 2004
@@ -115,15 +115,7 @@
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
-#endif /* __STDC__ */
+#include "mylibwrap.h"
 #endif /* HAVE_LIBWRAP */
 
 #ifdef HAVE_SYS_MMAN_H

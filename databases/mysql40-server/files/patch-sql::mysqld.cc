--- sql/mysqld.cc.orig	Sat Dec 18 18:25:05 2004
+++ sql/mysqld.cc	Sun Jan  9 12:43:21 2005
@@ -99,7 +99,7 @@
 #endif /* __WIN__ */
 
 #ifdef HAVE_LIBWRAP
-#include <tcpd.h>
+#include "mytcpd.h"
 #include <syslog.h>
 #ifdef NEED_SYS_SYSLOG_H
 #include <sys/syslog.h>
@@ -107,15 +107,6 @@
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
 #endif /* HAVE_LIBWRAP */
 
 #ifdef HAVE_SYS_MMAN_H
@@ -3240,8 +3231,8 @@
 	struct request_info req;
 	signal(SIGCHLD, SIG_DFL);
 	request_init(&req, RQ_DAEMON, libwrapName, RQ_FILE, new_sock, NULL);
-	my_fromhost(&req);
-	if (!my_hosts_access(&req))
+	fromhost(&req);
+	if (!hosts_access(&req))
 	{
 	  /*
 	    This may be stupid but refuse() includes an exit(0)
@@ -3249,7 +3240,7 @@
 	    clean_exit() - same stupid thing ...
 	  */
 	  syslog(deny_severity, "refused connect from %s",
-		 my_eval_client(&req));
+		 eval_client(&req));
 
 	  /*
 	    C++ sucks (the gibberish in front just translates the supplied

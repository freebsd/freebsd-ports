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
@@ -136,15 +136,6 @@
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
 #endif /* HAVE_LIBWRAP */
 
 #ifdef HAVE_SYS_MMAN_H
@@ -3565,8 +3556,8 @@
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
@@ -3574,7 +3565,7 @@
 	    clean_exit() - same stupid thing ...
 	  */
 	  syslog(deny_severity, "refused connect from %s",
-		 my_eval_client(&req));
+		 eval_client(&req));
 
 	  /*
 	    C++ sucks (the gibberish in front just translates the supplied

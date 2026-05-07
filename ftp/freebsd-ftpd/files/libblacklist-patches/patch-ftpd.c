--- ftpd.c.orig	2026-05-07 15:15:50 UTC
+++ ftpd.c
@@ -77,7 +77,7 @@
 #include <security/pam_appl.h>
 #endif
 
-#include "blocklist_client.h"
+#include "blacklist_client.h"
 #include "pathnames.h"
 #include "extern.h"
 
@@ -126,7 +126,7 @@ int	noguestmod = 1;		/* anon users may not modify exis
 int	noguestretr = 0;	/* RETR command is disabled for anon users. */
 int	noguestmkd = 0;		/* MKD command is disabled for anon users. */
 int	noguestmod = 1;		/* anon users may not modify existing files. */
-int	use_blocklist = 0;
+int	use_blacklist = 0;
 
 off_t	file_size;
 off_t	byte_count;
@@ -293,10 +293,10 @@ main(int argc, char *argv[], char **envp)
 			break;
 
 		case 'B':
-#ifdef USE_BLOCKLIST
-			use_blocklist = 1;
+#ifdef USE_BLACKLIST
+			use_blacklist = 1;
 #else
-			syslog(LOG_WARNING, "not compiled with USE_BLOCKLIST support");
+			syslog(LOG_WARNING, "not compiled with USE_BLACKLIST support");
 #endif
 			break;
 
@@ -630,7 +630,7 @@ gotchild:
 		reply(220, "%s FTP server (%s) ready.", hostname, version);
 	else
 		reply(220, "FTP server ready.");
-	BLOCKLIST_INIT();
+	BLACKLIST_INIT();
 	for (;;)
 		(void) yyparse();
 	/* NOTREACHED */
@@ -1043,7 +1043,7 @@ user(char *name)
 		    (checkuser(_PATH_FTPUSERS, name, 1, NULL, &ecode) ||
 		    (ecode != 0 && ecode != ENOENT))) {
 			reply(530, "User %s access denied.", name);
-			BLOCKLIST_NOTIFY(BLOCKLIST_AUTH_FAIL, STDIN_FILENO, "Access denied");
+			BLACKLIST_NOTIFY(BLACKLIST_AUTH_FAIL, STDIN_FILENO, "Access denied");
 			if (logging)
 				syslog(LOG_NOTICE,
 				    "FTP LOGIN REFUSED FROM %s, %s",
@@ -1387,7 +1387,7 @@ skip:
 		 */
 		if (rval) {
 			reply(530, "Login incorrect.");
-			BLOCKLIST_NOTIFY(BLOCKLIST_AUTH_FAIL, STDIN_FILENO, "Login incorrect");
+			BLACKLIST_NOTIFY(BLACKLIST_AUTH_FAIL, STDIN_FILENO, "Login incorrect");
 			if (logging) {
 				syslog(LOG_NOTICE,
 				    "FTP LOGIN FAILED FROM %s",
@@ -1405,7 +1405,7 @@ skip:
 			}
 			return;
 		} else {
-			BLOCKLIST_NOTIFY(BLOCKLIST_AUTH_OK, STDIN_FILENO, "Login successful");
+			BLACKLIST_NOTIFY(BLACKLIST_AUTH_OK, STDIN_FILENO, "Login successful");
 		}
 	}
 	login_attempts = 0;		/* this time successful */
@@ -1425,7 +1425,7 @@ skip:
 				*remote_ip = 0;
 		remote_ip[sizeof(remote_ip) - 1] = 0;
 		if (!auth_hostok(lc, remotehost, remote_ip)) {
-			BLOCKLIST_NOTIFY(BLOCKLIST_AUTH_FAIL, STDIN_FILENO, "Permission denied");
+			BLACKLIST_NOTIFY(BLACKLIST_AUTH_FAIL, STDIN_FILENO, "Permission denied");
 			syslog(LOG_INFO|LOG_AUTH,
 			    "FTP LOGIN FAILED (HOST) as %s: permission denied.",
 			    pw->pw_name);

--- src/ftpd.c.orig	Wed Apr 25 08:25:43 2001
+++ src/ftpd.c	Sat May 26 16:46:35 2001
@@ -102,6 +102,8 @@
  * FTP server.
  */
 
+#define NO_UTMP
+
 #define	FTP_NAMES
 
 #include "lukemftpd.h"
@@ -780,9 +782,9 @@
 	if (logged_in) {
 #ifdef NO_UTMP
 		if (dowtmp)
-			logwtmp(ttyline, "", "");
+			ftpd_logwtmp(ttyline, "", "");
 		if (doutmp)
-			logout(utmp.ut_line);
+			ftpd_logout(utmp.ut_line);
 #endif /* NO_UTMP */
 	}
 			/* reset login state */
@@ -912,7 +914,7 @@
 			/* open wtmp before chroot */
 #ifdef NO_UTMP
 	if (dowtmp)
-		logwtmp(ttyline, pw->pw_name, remotehost);
+		ftpd_logwtmp(ttyline, pw->pw_name, remotehost);
 
 			/* open utmp before chroot */
 	if (doutmp) {
@@ -921,7 +923,7 @@
 		(void)strncpy(utmp.ut_name, pw->pw_name, sizeof(utmp.ut_name));
 		(void)strncpy(utmp.ut_host, remotehost, sizeof(utmp.ut_host));
 		(void)strncpy(utmp.ut_line, ttyline, sizeof(utmp.ut_line));
-		login(&utmp);
+		ftpd_login(&utmp);
 	}
 #endif /* NO_UTMP */
 
@@ -2155,9 +2157,9 @@
 	if (logged_in) {
 #ifdef NO_UTMP
 		if (dowtmp)
-			logwtmp(ttyline, "", "");
+			ftpd_logwtmp(ttyline, "", "");
 		if (doutmp)
-			logout(utmp.ut_line);
+			ftpd_logout(utmp.ut_line);
 #endif /* NO_UTMP */
 #ifdef KERBEROS
 		if (!notickets && krbtkfile_env)

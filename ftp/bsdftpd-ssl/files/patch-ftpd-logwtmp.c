--- ftpd/logwtmp.c.orig	2004-12-19 18:44:42 UTC
+++ ftpd/logwtmp.c
@@ -48,13 +48,18 @@ __FBSDID("$FreeBSD: src/libexec/ftpd/log
 #include <arpa/inet.h>
 #include <sys/socket.h>
 
+#include <sys/param.h>
+#if __FreeBSD_version < 900007
 #include <fcntl.h>
 #include <time.h>
-#if 0 /* Original FreeBSD 5.0 code */
+#if 1 /* Original FreeBSD 5.0 code */
 #include <timeconv.h>
 #endif
 #include <netdb.h>
 #include <utmp.h>
+#else
+#include <utmpx.h>
+#endif
 #include <unistd.h>
 #include <stdio.h>
 #include <string.h>
@@ -63,6 +68,7 @@ __FBSDID("$FreeBSD: src/libexec/ftpd/log
 
 #include <port_base.h>
 
+#ifndef _UTMPX_H_
 static int fd = -1;
 
 /*
@@ -94,7 +100,7 @@ ftpd_logwtmp(line, name, addr)
 		(void)strncpy(ut.ut_line, line, sizeof(ut.ut_line));
 		(void)strncpy(ut.ut_name, name, sizeof(ut.ut_name));
 		(void)strncpy(ut.ut_host, host, sizeof(ut.ut_host));
-#if 0 /* Original FreeBSD 5.0 code */
+#if 1 /* Original FreeBSD 5.0 code */
 		ut.ut_time = _time_to_time32(time(NULL));
 #else /* Portable code from FreeBSD 4.8 */
 		(void)time(&ut.ut_time);
@@ -104,3 +110,31 @@ ftpd_logwtmp(line, name, addr)
 			(void)ftruncate(fd, buf.st_size);
 	}
 }
+#else /* Original FreeBSD 9.0 code */
+void
+ftpd_logwtmp(char *id, char *user, struct sockaddr *addr)
+{
+	struct utmpx ut;
+
+	memset(&ut, 0, sizeof(ut));
+
+	if (user != NULL) {
+		/* Log in. */
+		ut.ut_type = USER_PROCESS;
+		(void)strncpy(ut.ut_user, user, sizeof(ut.ut_user));
+		if (addr != NULL)
+			realhostname_sa(ut.ut_host, sizeof(ut.ut_host),
+			    addr, addr->sa_len);
+	} else {
+		/* Log out. */
+		ut.ut_type = DEAD_PROCESS;
+	}
+
+	ut.ut_pid = getpid();
+	gettimeofday(&ut.ut_tv, NULL);
+	(void)strncpy(ut.ut_id, id, sizeof(ut.ut_id));
+	(void)strncpy(ut.ut_line, "ftpd", sizeof(ut.ut_line));
+
+	pututxline(&ut);
+}
+#endif

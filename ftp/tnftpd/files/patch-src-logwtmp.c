--- src/logwtmp.c-orig	Thu Jan 29 15:45:32 2004
+++ src/logwtmp.c	Thu Jan 29 15:47:34 2004
@@ -42,11 +42,13 @@
 
 #include <sys/types.h>
 #include <sys/param.h>
+#include <sys/socket.h>
 #include <sys/time.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
 
 #include <fcntl.h>
+#include <netdb.h>
 #include <signal.h>
 #include <stdio.h>
 #include <string.h>
@@ -56,7 +58,6 @@
 #ifdef SUPPORT_UTMPX
 #include <utmpx.h>
 #endif
-#include <util.h>
 
 #ifdef KERBEROS5
 #include <krb5/krb5.h>
@@ -79,6 +80,26 @@
 {
 	struct utmp ut;
 	struct stat buf;
+
+	if (strlen(host) > UT_HOSTSIZE) {
+		struct addrinfo hints, *res;
+		int error;
+		static char hostbuf[BUFSIZ];
+
+		memset(&hints, 0, sizeof(hints));
+		hints.ai_family = PF_UNSPEC;
+		error = getaddrinfo(host, NULL, &hints, &res);
+		if (error)
+			host = "invalid hostname";
+		else {
+			getnameinfo(res->ai_addr, res->ai_addrlen,
+				hostbuf, sizeof(hostbuf), NULL, 0,
+				NI_NUMERICHOST);
+			host = hostbuf;
+			if (strlen(host) > UT_HOSTSIZE)
+				hostbuf[UT_HOSTSIZE] = '\0';
+		}
+	}
 
 	if (fd < 0 && (fd = open(_PATH_WTMP, O_WRONLY|O_APPEND, 0)) < 0)
 		return;

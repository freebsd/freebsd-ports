--- src/logwtmp.c-orig	Mon Feb 24 07:38:44 2003
+++ src/logwtmp.c	Thu Jan 22 12:05:36 2004
@@ -46,10 +46,12 @@
 
 #include <sys/types.h>
 #include <sys/param.h>
+#include <sys/socket.h>
 #include <sys/time.h>
 #include <sys/stat.h>
 
 #include <fcntl.h>
+#include <netdb.h>
 #include <setjmp.h>
 #include <signal.h>
 #include <stdio.h>
@@ -57,7 +59,6 @@
 #include <time.h>
 #include <unistd.h>
 #include <utmp.h>
-#include <util.h>
 
 #ifdef KERBEROS5
 #include <krb5/krb5.h>
@@ -77,6 +78,26 @@
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
+				host[UT_HOSTSIZE] = '\0';
+		}
+	}
 
 	if (fd < 0 && (fd = open(_PATH_WTMP, O_WRONLY|O_APPEND, 0)) < 0)
 		return;


FreeBSD does not have header file util.h, fortunately it is not needed. Add
header files sys/socket.h and netdb.h for getaddrinfo() and getnameinfo().
If host name is longer than UT_HOSTSIZE (16 characters), log numeric
address to utmp. Rewrite utmpx support.

--- src/logwtmp.c.orig	2008-09-21 16:44:01.000000000 +0200
+++ src/logwtmp.c	2008-09-21 16:44:01.000000000 +0200
@@ -46,11 +46,13 @@
 
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
@@ -63,7 +65,6 @@
 #ifdef SUPPORT_UTMPX
 #include <utmpx.h>
 #endif
-#include <util.h>
 
 #ifdef KERBEROS5
 #include <krb5/krb5.h>
@@ -95,6 +96,26 @@
 	struct utmp ut;
 	struct stat buf;
 
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
+
 	if (fd < 0)
 		return;
 	if (fstat(fd, &buf) == 0) {
@@ -109,7 +130,7 @@
 }
 #endif
 
-#ifdef SUPPORT_UTMPX
+#if 0
 static int fdx = -1;
 
 void

--- src/logwtmp.c.old	Sat May 26 16:08:11 2001
+++ src/logwtmp.c	Sat May 26 16:15:20 2001
@@ -46,10 +46,30 @@
  * after login, but before logout).
  */
 void
-logwtmp(const char *line, const char *name, const char *host)
+ftpd_logwtmp(const char *line, const char *name, const char *host)
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

--- etc/conserver/master.c.orig	2000-08-02 11:39:42.000000000 -0700
+++ etc/conserver/master.c	2013-09-18 00:48:10.621087079 -0700
@@ -200,17 +200,17 @@
 
 	if ((msfd=socket(AF_INET, SOCK_STREAM, 0)) < 0) {
 		fprintf(stderr, "%s: socket: %s\n", progname, strerror(errno));
-		return;
+		return 0;
 	}
 #if defined(SO_REUSEADDR) && defined(SOL_SOCKET)
 	if (setsockopt(msfd, SOL_SOCKET, SO_REUSEADDR, (char *)&iTrue, sizeof(iTrue))<0) {
 		fprintf(stderr, "%s: setsockopt: %s\n", progname, strerror(errno));
-		return;
+		return 0;
 	}
 #endif
 	if (bind(msfd, (struct sockaddr *)&master_port, sizeof(master_port))<0) {
 		fprintf(stderr, "%s: bind: %s\n", progname, strerror(errno));
-		return;
+		return 0;
 	}
 	if (listen(msfd, SOMAXCONN) < 0) {
 		fprintf(stderr, "%s: listen: %s\n", progname, strerror(errno));

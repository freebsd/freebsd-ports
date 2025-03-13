--- src/daemon.c.orig	2003-10-26 22:10:19 UTC
+++ src/daemon.c
@@ -33,6 +33,7 @@
 #include <signal.h>
 #include <sys/wait.h>
 #include <pwd.h>
+#include <err.h>
 
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -51,20 +52,35 @@
 
 int acceptloop(int sock)
 {
-	int	connect, pid, len;
+	int	connect, pid, otherpid;
+	socklen_t len;
 	struct sockaddr_in client;
 
 	/*
 	 * Go into background.
 	 */
 	
-	if (debug != 0)
-		; /* Do not fork in debug mode */
+	pfh = NULL;
 
-	else if ((pid = fork()) > 0)
-		exit (0);
+	if (debug == 0) {
+		pfh = pidfile_open(pidfile, 0600, &otherpid);
+		if (pfh == NULL) {
+			if (errno == EEXIST) {
+				errx(EXIT_FAILURE, "ftp.proxy already running, pid %jd.",
+						(intmax_t)otherpid);
+			}
+			warnx("Cannot open or create pid file %s", pidfile);
+		}
+		if (daemon(0, 0) == -1) {
+			warnx("Cannot daemonize");
+			pidfile_remove(pfh);
+			exit(EXIT_FAILURE);
+		}
+		pidfile_write(pfh);
+	}
 
 	fprintf (stderr, "\nstarting ftp.proxy %s in daemon mode ...\n", VERSION);
+
 	while (1) {
 
 		/*
@@ -82,7 +98,7 @@ int acceptloop(int sock)
 
 		if ((pid = fork()) < 0) {
 			fprintf (stderr, "%04X: can't fork process: %s\n", getpid(), strerror(errno));
-			exit (1);
+			exit(EXIT_FAILURE);
 			}
 		else if (pid == 0) {
 			int optlen;
@@ -112,7 +128,9 @@ int acceptloop(int sock)
 
 	close (1);
 	fprintf (stderr, "%04X: terminating\n", getpid());
-
-	exit (0);
+	if (pfh != NULL) {
+		pidfile_remove(pfh);
+	}
+	exit (EXIT_SUCCESS);
 }
 

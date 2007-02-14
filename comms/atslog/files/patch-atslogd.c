--- atslogd/atslogd.c.orig	Sun Jan 28 17:52:03 2007
+++ atslogd/atslogd.c	Wed Feb 14 16:22:23 2007
@@ -143,16 +143,54 @@
 	close(hCom);
 }
 
-static int 
-daemonize(void)
-{
-	int		rc;
-	rc = fork();
-	if (rc == (-1))
-		return (-1);
-	if (rc != 0)
-		_exit(EX_OK);
-	return rc;
+/* taken from the http://www.developerweb.net/forum/archive/index.php/t-3025.html */
+void daemonize(void) {
+	int fd;
+	switch (fork()) {
+		case 0:
+		break;
+		case -1:
+		// Error
+		fprintf(stderr, "Error demonizing (fork)! %d - %s\n", errno, strerror(errno));
+		exit(0);
+		break;
+		default:
+		_exit(0);
+	}
+	
+	if (setsid() < 0) {
+		fprintf(stderr, "Error demonizing (setsid)! %d - %s\n", errno, strerror(errno));
+		exit(0);
+	}
+	switch (fork()) {
+		case 0:
+		break;
+		case -1:
+		// Error
+		fprintf(stderr, "Error demonizing (fork2)! %d - %s\n", errno, strerror(errno));
+		exit(0);
+		break;
+		default:
+		_exit(0);
+	}
+	/* Are we really need this? */
+	// chdir("/");
+	
+	fd = open("/dev/null", O_RDONLY);
+	if (fd != 0) {
+		dup2(fd, 0);
+		close(fd);
+	}
+	fd = open("/dev/null", O_WRONLY);
+	if (fd != 1) {
+		dup2(fd, 1);
+		close(fd);
+	}
+	fd = open("/dev/null", O_WRONLY);
+	if (fd != 2) {
+		dup2(fd, 2);
+		close(fd);
+	}
 }
 
 FILE           *
@@ -755,6 +793,9 @@
 	argc -= optind;
 	argv += optind;
 
+	if (do_daemonize)
+		daemonize();
+
 	if (logfile) {
 		errout = fopen(logfile, "at");
 		if (errout == NULL) {
@@ -772,28 +813,22 @@
 	}
 	my_syslog("Starting");
 	
-	if (do_daemonize)
-		daemonize();
 	
 	pid = getpid();
-	
 	if (do_daemonize && pid == (-1)) {
 		my_syslog("Can't become daemon, exiting");
 		my_exit(1);
-	}
+	} 
 	pfd = open_pid();
 	if (pfd != NULL) {
-		(void)fprintf(pfd, "%ld\n", (long)pid);
+		(void)fprintf(pfd, "%d\n", getpid());
 		fclose(pfd);
 	} else {
 		my_syslog("Can't write to '%s' PID file, exiting", pid_file);
 		my_exit(1);
 	}
 	
-	if (do_daemonize)
-		pid = daemonize();
-	else
-		pid = getpid();
+	pid = getpid();
 
 	if (do_daemonize && pid == (-1)) {
 		my_syslog("Can't become daemon, exiting");

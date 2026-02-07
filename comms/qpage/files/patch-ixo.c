--- ixo.c.orig	1999-01-02 01:59:33 UTC
+++ ixo.c
@@ -368,7 +368,6 @@ hangup_modem(int fd)
 	if (tcsetattr(fd, TCSANOW, &ti) < 0) {
 		qpage_log(LOG_DEBUG, "tcsetattr(): %s", strerror(errno));
 		closemodem(fd);
-		return;
 	}
 
 	/*

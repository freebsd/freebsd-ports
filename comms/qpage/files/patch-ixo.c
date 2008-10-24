--- ixo.c.orig	1999-01-01 20:59:33.000000000 -0500
+++ ixo.c	2008-10-20 00:10:55.367858145 -0400
@@ -368,7 +368,6 @@
 	if (tcsetattr(fd, TCSANOW, &ti) < 0) {
 		qpage_log(LOG_DEBUG, "tcsetattr(): %s", strerror(errno));
 		closemodem(fd);
-		return;
 	}
 
 	/*

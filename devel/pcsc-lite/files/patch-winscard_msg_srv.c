--- src/winscard_msg_srv.c.orig	Mon Jan 22 16:26:53 2007
+++ src/winscard_msg_srv.c	Mon Jan 22 16:29:52 2007
@@ -169,6 +169,10 @@
 {
 	fd_set read_fd;
 	int selret;
+	struct timeval tv;
+
+	tv.tv_sec = 1;
+	tv.tv_usec = 0;
 
 	FD_ZERO(&read_fd);
 
@@ -178,7 +182,7 @@
 	FD_SET(commonSocket, &read_fd);
 
 	selret = select(commonSocket + 1, &read_fd, (fd_set *) NULL,
-		(fd_set *) NULL, NULL);
+		(fd_set *) NULL, &tv);
 
 	if (selret < 0)
 	{
@@ -189,6 +193,10 @@
 			strerror(errno));
 		return -1;
 	}
+
+	if (selret == 0)
+		/* timeout */
+		return 2;
 
 	/*
 	 * A common pipe packet has arrived - it could be a new application

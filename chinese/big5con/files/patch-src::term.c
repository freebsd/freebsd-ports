--- src/term.c.orig	Mon Apr 15 09:46:48 1996
+++ src/term.c	Tue Nov 26 11:45:26 2002
@@ -205,7 +205,7 @@
 	    PollCursor(TRUE);
 	}
 	if (FD_ISSET(sockFd, &readFds)) SocketInterface(sockFd);
-	if (mInfo.has_mouse) {
+	if (mInfo.has_mouse && mouseFd > 0) {
 	    if (FD_ISSET(mouseFd, &readFds) && con.active) {
 		i = read(mouseFd, buff, BUFSIZ);
 		if (i > 0) MouseGetPacket(buff, i);

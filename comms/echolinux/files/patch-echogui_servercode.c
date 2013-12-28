--- echogui/servercode.c.orig	2013-12-27 22:13:30.194795239 -0500
+++ echogui/servercode.c	2013-12-27 22:13:50.872793794 -0500
@@ -641,7 +641,7 @@
 	  FD_CLR(serverSocket, &exceptFds);
 	  FD_CLR(serverSocket, &writeFds);
 	  close(serverSocket);
-	  serverPortState == CLOSED;
+	  serverPortState = CLOSED;
 	  if(serverShutdown)
 	    quit = 1;
 	  else{

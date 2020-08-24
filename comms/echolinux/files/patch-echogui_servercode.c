--- echogui/servercode.c.orig	2006-02-24 19:28:15 UTC
+++ echogui/servercode.c
@@ -82,7 +82,7 @@ fd_set writeFds, testWriteFds;
 fd_set exceptFds, testExceptFds;
 
 int    doTimeout = 0;
-struct timeval timeout;
+static struct timeval timeout;
 struct tm *tm_ptr;
 time_t    theTime;
 char      logTime[20];
@@ -641,7 +641,7 @@ int doServer(void *ptr){
 	  FD_CLR(serverSocket, &exceptFds);
 	  FD_CLR(serverSocket, &writeFds);
 	  close(serverSocket);
-	  serverPortState == CLOSED;
+	  serverPortState = CLOSED;
 	  if(serverShutdown)
 	    quit = 1;
 	  else{

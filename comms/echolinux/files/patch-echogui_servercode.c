--- echogui/servercode.c.orig	Tue Feb  3 04:48:41 2004
+++ echogui/servercode.c	Mon Jul  5 00:11:42 2004
@@ -216,22 +216,13 @@
 
   serverFd = fdopen(serverSocket, "r"); 
 
-  memset(sendBuf, 0x6c, 1);
-  result = write(serverSocket, sendBuf, 1);
-
   /* Get the local time */
   (void) time(&theTime);
   tm_ptr = localtime(&theTime);
   strftime(logTime, 6, "%H:%M", tm_ptr);
   
-  strcpy(sendBuf, callsign);
-  strcat(sendBuf,"\254\254");
-  strcat(sendBuf, password);
-  strcat(sendBuf, "\015ONLINE3.38(");
-  strcat(sendBuf, logTime);
-  strcat(sendBuf, ")\015");
-  strcat(sendBuf,location);
-  strcat(sendBuf,"\015");
+  sprintf(sendBuf,"\x6c%s\xac\xac%s\rONLINE3.38(%s)\r%s\r",
+  	callsign, password, logTime, location);
 
   result = write(serverSocket, sendBuf, strlen(sendBuf));
 
@@ -677,33 +668,9 @@
       }
 
       if(FD_ISSET(serverSocket, &testWriteFds)){
-	doTimeout = 0;
-	(void) time(&theTime);
-	tm_ptr = localtime(&theTime);
-	strftime(logTime, 20, "%H:%M:%S", tm_ptr);
-	i = connect(serverSocket, (struct sockaddr *) &adr_srvr,len_inet);
-	// printf("Connect returned a %d, errno = %s\n", i, strerror(errno));
-	if(i){
-	  // printf("%s serverSocket has an error, %d: %s.\n", 
-	  // logTime, errno, strerror(errno));
-	  FD_CLR(serverSocket, &exceptFds);
-	  FD_CLR(serverSocket, &writeFds);
-	  close(serverSocket);
-	  serverPortState == CLOSED;
-	  if(serverShutdown)
-	    quit = 1;
-	  else{
-	    pServerCurrent = pServerCurrent->next;
-	    openSocket();
-	  }
-	}  
-	else{
-	  //printf("%s Cool, no error, server on socket %d.\n", 
-	  // logTime, serverSocket);
-	  serverPortState = CONNECTED;
-	  FD_CLR(serverSocket, &writeFds);
-	  serverTask();
-	}
+	serverPortState = CONNECTED;
+	FD_CLR(serverSocket, &writeFds);
+	serverTask();
       }
 
       if(serverState != IDLE){    

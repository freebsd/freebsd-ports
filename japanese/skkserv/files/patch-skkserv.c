--- skkserv/skkserv.c.orig	1997-01-21 04:16:36.000000000 +0900
+++ skkserv/skkserv.c	2008-11-02 00:07:53.000000000 +0900
@@ -124,6 +124,8 @@
 int	clientsock[MAXCLNT];	/* socket for each client */
 int	nclients;	/* max index for active clients */
 
+char	listenaddr[NI_MAXHOST];
+
 main(argc, argv)
 char *argv[];
 {
@@ -166,6 +168,12 @@
       case 'P': 
 	if (parg +1 == argc) showusage();
 	portnum = atoi(argv[++parg]); break;
+      case 'a':
+      case 'A': 
+	if (parg +1 == argc) showusage();
+	strncpy(listenaddr, argv[++parg], sizeof(listenaddr) - 1);
+        listenaddr[sizeof(listenaddr) - 1] = '\0';
+        break;
       default: showusage();
       }
     } else if (setjisho == 0) {
@@ -232,9 +240,9 @@
 showusage()
 {
   fprintf(stderr, 
-	  "Usage: %s [-d] [-l logfile] [-p port] \n", pgmnm);
+	  "Usage: %s [-d] [-l logfile] [-p port] [-a listenaddr]\n", pgmnm);
   fprintf(stderr, 
-	  "       %s [-d] [-l logfile] [-p port] skk-jisho\n", pgmnm);
+	  "       %s [-d] [-l logfile] [-p port] [-a listenaddr] skk-jisho\n", pgmnm);
   exit(1);
 }
  
@@ -249,7 +257,21 @@
   
   bzero((char*)&sin, sizeof(sin));
   sin.sin_family = AF_INET;
-  sin.sin_addr.s_addr = htonl(INADDR_ANY);
+  if (listenaddr[0] == '\0') {
+	  sin.sin_addr.s_addr = htonl(INADDR_ANY);
+  } else {
+	  if (!inet_aton(listenaddr, &sin.sin_addr)) {
+		  struct hostent  *hp;
+		  struct in_addr  **pptr;
+		  
+		  if ((hp = gethostbyname(listenaddr)) == NULL) {
+			  err("could not resolve the specified listen address");
+		  }
+		  pptr = (struct in_addr **)hp->h_addr_list;
+		  memcpy(&sin.sin_addr.s_addr, pptr[0], sizeof(struct in_addr));
+	  }
+  }
+
   if (portnum == 0) {
 #ifdef PORTNUM
     portnum = PORTNUM;
@@ -476,7 +498,7 @@
 
     if (FD_ISSET(initsock, &readfds)) {
       len = sizeof(from);
-      if ((clientsock[nclients ++] = accept(initsock, &from, &len)) < 0) {
+      if ((clientsock[nclients ++] = accept(initsock, (struct sockaddr*)&from, &len)) < 0) {
 	err("accept error; something wrong happened with the socket");
       }
       if (nclients >= MAXDTAB - 3 - debug * 2) {

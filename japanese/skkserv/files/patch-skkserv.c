--- skkserv/skkserv.c.orig	1997-01-21 04:16:36.000000000 +0900
+++ skkserv/skkserv.c	2011-07-02 23:48:44.000000000 +0900
@@ -102,6 +102,8 @@
 
 #define err(m)	\
 	{if (debug) fprintf(errout, "%s: %s\n", pgmnm, m); exit(1);}
+#define nderr(m)	\
+	{fprintf(errout, "%s: %s\n", pgmnm, m); exit(1);}
 
 /*
  *	Global Variables
@@ -124,18 +126,25 @@
 int	clientsock[MAXCLNT];	/* socket for each client */
 int	nclients;	/* max index for active clients */
 
+char	listenaddr[NI_MAXHOST];
+uid_t	uid;
+gid_t	gid;
+
 main(argc, argv)
 char *argv[];
 {
   int	parg;
   int	setjisho = 0;
   int	ctlterm;	/* fildes for control terminal */
+  struct passwd *pwent;
   void	reread();
 
   pgmnm = argv[0];
   debug = 0;
   errout = stderr;
   portnum = 0;
+  uid = getuid();
+  gid = getgid();
 
   /* The following patch (a work-around due to "rsh" bug) was pointed 	*/
   /* out by kazushi@kubota.co.jp in the message "714" in SKK-ML		*/
@@ -155,7 +164,7 @@
 	if (parg + 1 == argc) showusage();
 	if ((errout = fopen(argv[++parg], "w")) == NULL) {
 	  fprintf(stderr, "%s: opening logfile \"%s\" failed\n", 
-		  pgmnm, *argv[parg]);
+		  pgmnm, argv[parg]);
 	  exit(1);
 	}
 	debug = 1; break;
@@ -166,6 +175,24 @@
       case 'P': 
 	if (parg +1 == argc) showusage();
 	portnum = atoi(argv[++parg]); break;
+      case 'u':
+      case 'U': 
+	if (parg + 1 == argc) showusage();
+	pwent = getpwnam(argv[++parg]);
+	if (pwent == NULL) {
+    		fprintf(stderr, 
+	 	   "%s: invalid uid \"%s\"\n", pgmnm, argv[parg]);
+		exit(1);
+	}
+	uid = pwent->pw_uid;
+	gid = pwent->pw_gid;
+        break;
+      case 'a':
+      case 'A': 
+	if (parg +1 == argc) showusage();
+	strncpy(listenaddr, argv[++parg], sizeof(listenaddr) - 1);
+        listenaddr[sizeof(listenaddr) - 1] = '\0';
+        break;
       default: showusage();
       }
     } else if (setjisho == 0) {
@@ -183,6 +210,17 @@
     exit(1);
   }
 
+  if (setgid(gid) == -1) {
+    fprintf(stderr, 
+	    "%s: setgid() failed\n", pgmnm);
+    exit(1);
+  }
+  if (setuid(uid) == -1) {
+    fprintf(stderr, 
+	    "%s: setuid() failed\n", pgmnm);
+    exit(1);
+  }
+
   set_hname();
 
   /* make socket */
@@ -232,9 +270,11 @@
 showusage()
 {
   fprintf(stderr, 
-	  "Usage: %s [-d] [-l logfile] [-p port] \n", pgmnm);
+	  "Usage: %s [-d] [-l logfile] [-p port] [-a listenaddr] [-u uid]\n",
+	  pgmnm);
   fprintf(stderr, 
-	  "       %s [-d] [-l logfile] [-p port] skk-jisho\n", pgmnm);
+	  "       %s [-d] [-l logfile] [-p port] [-a listenaddr] [-u uid]"
+	  " skk-jisho\n", pgmnm);
   exit(1);
 }
  
@@ -249,27 +289,41 @@
   
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
+			  nderr("could not resolve the specified listen address");
+		  }
+		  pptr = (struct in_addr **)hp->h_addr_list;
+		  memcpy(&sin.sin_addr.s_addr, pptr[0], sizeof(struct in_addr));
+	  }
+  }
+
   if (portnum == 0) {
 #ifdef PORTNUM
     portnum = PORTNUM;
 #else
     if ((sp = getservbyname(SERVICE_NAME, "tcp")) == NULL)
-      err("service name is undefined in /etc/services file");
+      nderr("service name is undefined in /etc/services file");
     portnum = ntohs(sp->s_port);
 #endif
   }
   sin.sin_port = htons(portnum); 
 
   if ((initsock = socket(PF_INET, SOCK_STREAM, 0)) < 0)
-    err("socket error; socket cannot be created");
+    nderr("socket error; socket cannot be created");
   if (setsockopt(initsock, SOL_SOCKET, SO_REUSEADDR, 
 		 &optbuf, sizeof(optbuf)) < 0)
-    err("socket error; cannot set socket option");
+    nderr("socket error; cannot set socket option");
   if (bind(initsock, (struct sockaddr *)&sin, sizeof(sin))< 0) 
-    err("bind error; the socket is already used");
+    nderr("bind error; the socket is already used");
   if (listen(initsock, MAXQUE) < 0) 
-    err("listen error; something wrong happened with the socket");
+    nderr("listen error; something wrong happened with the socket");
   if (debug) {
     fprintf(errout, "file descriptor for initsock is %d\n", initsock);
     fflush(errout);
@@ -382,6 +436,10 @@
   code = KANA_END;
 
   while ((c = fgetc(jisho)) != EOF) {
+	if (c == '>') {
+		fgets(buf, BUFSIZE, jisho);
+		continue;
+	}
     target = ((c & 0xff)<< 8) | (fgetc(jisho) & 0xff);
     if (target == STRMARK) {
       fgets(buf, BUFSIZE, jisho);
@@ -476,7 +534,7 @@
 
     if (FD_ISSET(initsock, &readfds)) {
       len = sizeof(from);
-      if ((clientsock[nclients ++] = accept(initsock, &from, &len)) < 0) {
+      if ((clientsock[nclients ++] = accept(initsock, (struct sockaddr*)&from, &len)) < 0) {
 	err("accept error; something wrong happened with the socket");
       }
       if (nclients >= MAXDTAB - 3 - debug * 2) {

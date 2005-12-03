--- netio.c.orig	Thu Apr 19 14:21:02 2001
+++ netio.c	Sat Dec  3 16:14:21 2005
@@ -477,14 +477,22 @@
 
 /* TCP/IP code */
 
-int nPort = 0x494F; /* "IO" */
+int nPort = 0x494F; /* "IO" */
+#ifdef USE_IPV6
+struct in6_addr addr_server;
+#else
 struct in_addr addr_server;
+#endif
 
 void TcpIpServer(void *arg)
 {
   char *cBuffer;
-  int bQuit = 0;
-  struct sockaddr_in sa_server, sa_client;
+  int bQuit = 0;
+#ifdef USE_IPV6
+  struct sockaddr_in6 sa_server, sa_client;
+#else
+  struct sockaddr_in sa_server, sa_client;
+#endif
   int server, client, length;
   struct timeval tv;
   fd_set fds;
@@ -495,17 +503,27 @@
     perror("malloc()");
     return;
   }
-
-  if ((server = socket(PF_INET, SOCK_STREAM, 0)) < 0)
+
+#ifdef USE_IPV6
+  if ((server = socket(PF_INET6, SOCK_STREAM, 0)) < 0)
+#else
+  if ((server = socket(PF_INET, SOCK_STREAM, 0)) < 0)
+#endif
   {
     psock_errno("socket()");
     free(cBuffer);
     return;
   }
-
-  sa_server.sin_family = AF_INET;
+
+#ifdef USE_IPV6
+  sa_server.sin6_family = AF_INET6;
+  sa_server.sin6_port = htons(nPort);
+  sa_server.sin6_addr = in6addr_any;
+#else
+  sa_server.sin_family = AF_INET;
   sa_server.sin_port = htons(nPort);
   sa_server.sin_addr.s_addr = INADDR_ANY;
+#endif
 
   if (bind(server, (struct sockaddr *) &sa_server, sizeof(sa_server)) < 0)
   {
@@ -524,8 +542,12 @@
   }
 
   for (;;)
-  {
+  {
+#ifdef USE_IPV6
+    printf("TCP/IP server Listening (IPv6).\n");
+#else
     printf("TCP/IP server Listening.\n");
+#endif
 
     FD_ZERO(&fds);
     FD_SET(server, &fds);
@@ -575,8 +597,12 @@
   TIMER nTimer;
   long nTime;
   long nData;
-  int i;
-  struct sockaddr_in sa_server;
+#ifdef USE_IPV6
+  struct sockaddr_in6 sa_client;
+#else
+  struct sockaddr_in sa_client;
+#endif
+  int i;
   int server;
   int rc;
 
@@ -585,19 +611,28 @@
     perror("malloc()");
     return;
   }
-
-  sa_server.sin_family = AF_INET;
-  sa_server.sin_port = htons(nPort);
-  sa_server.sin_addr = addr_server;
-
+
+#ifdef USE_IPV6
+  sa_client.sin6_family = AF_INET6;
+  sa_client.sin6_port = htons(nPort);
+  sa_client.sin6_addr = addr_server;
+#else
+  sa_client.sin_family = AF_INET;
+  sa_client.sin_port = htons(nPort);
+  sa_client.sin_addr = addr_server;
+#endif
+
+#ifdef USE_IPV6
+  if ((server = socket(PF_INET6, SOCK_STREAM, 0)) < 0)
+#else
   if ((server = socket(PF_INET, SOCK_STREAM, 0)) < 0)
+#endif
   {
     psock_errno("socket()");
     free(cBuffer);
     return;
-  }
-
-  if (connect(server, (struct sockaddr *) &sa_server, sizeof(sa_server)) < 0)
+  }
+  if (connect(server, (struct sockaddr *) &sa_client, sizeof(sa_client)) < 0)
   {
     psock_errno("connect()");
     soclose(server);
@@ -664,13 +699,17 @@
 {
   printf(
 #ifndef USE_NETBIOS
+#ifdef USE_IPV6
+	 "\nUsage: netio6 [-s] [-p <port>] [<server>]\n"
+#else
 	 "\nUsage: netio [-s] [-p <port>] [<server>]\n"
+#endif
 	 "\n\t-s\t\trun server side of benchmark (otherwise run client)"
 	 "\n\t-p <port>\tuse this port instead of the default (%d)"
          "\n\t<server>\tif the client side of the benchmark is running,"
 	 "\n\t\t\ta server host name is required\n"
-#else
-	 "\nUsage: netio [-s] [-t | -n] [-p <port>] [-a <adapter>] [<server>]\n"
+#else
+	 "\nUsage: netio [-s] [-t | -n] [-p <port>] [-a <adapter>] [<server>]\n"
 	 "\n\t-s\trun server side of benchmark (otherwise run client)"
 	 "\n\t-t\tuse TCP/IP protocol for benchmark"
 	 "\n\t-p <port>\tuse this port for TCP/IP (default is %d)"
@@ -766,14 +805,28 @@
       if (optind == argc)
 	usage();
 
-      if (isdigit(*argv[optind]))
-	addr_server.s_addr = inet_addr(argv[optind]);
+      if (isdigit(*argv[optind])
+#ifdef USE_IPV6
+	|| *argv[optind] == ':')
+	inet_pton(AF_INET6, argv[optind], &addr_server);
+#else
+	)
+	addr_server.s_addr = inet_addr(argv[optind]);
+#endif
       else
-      {
-	if ((host = gethostbyname(argv[optind])) == NULL)
+      {
+#ifdef USE_IPV6
+	if ((host = gethostbyname2(argv[optind], AF_INET6)) == NULL)
+#else
+	if ((host = gethostbyname(argv[optind])) == NULL)
+#endif
 	  return psock_errno("gethostbyname()"), 1;
 
-	addr_server = * (struct in_addr *) (host->h_addr);
+#ifdef USE_IPV6
+	addr_server = * (struct in6_addr *) (host->h_addr);
+#else
+	addr_server = * (struct in_addr *) (host->h_addr);
+#endif
       }
     }
   }

--- netio.c.orig	Tue Aug 30 16:47:18 2005
+++ netio.c	Sat Sep  2 13:46:50 2006
@@ -782,8 +782,13 @@
 const int sobufsize = 131072;
 int nPort = DEFAULTPORT;
 int nAuxPort = DEFAULTPORT + 1;
+#ifdef USE_IPV6
+struct in6_addr addr_server;
+struct in6_addr addr_local;
+#else
 struct in_addr addr_server;
 struct in_addr addr_local;
+#endif
 
 int udpsocket, udpd;
 unsigned long nUDPCount;
@@ -794,7 +799,11 @@
   char *cBuffer;
   CONTROL ctl;
   long long nData;
+#ifdef USE_IPV6
+  struct sockaddr_in6 sa_server, sa_client;
+#else
   struct sockaddr_in sa_server, sa_client;
+#endif
   int server, client;
   size_t length;
   struct timeval tv;
@@ -808,7 +817,11 @@
     return THREADRESULT;
   }
 
+#ifdef USE_IPV6
+  if ((server = socket(PF_INET6, SOCK_STREAM, 0)) < 0)
+#else
   if ((server = socket(PF_INET, SOCK_STREAM, 0)) < 0)
+#endif
   {
     psock_errno("socket()");
     free(cBuffer);
@@ -818,10 +831,15 @@
   setsockopt(server, SOL_SOCKET, SO_RCVBUF, (char *) &sobufsize, sizeof(sobufsize));
   setsockopt(server, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
 
+#ifdef USE_IPV6
+  sa_server.sin6_family = AF_INET6;
+  sa_server.sin6_port = htons(nPort);
+  sa_server.sin6_addr = addr_local;
+#else
   sa_server.sin_family = AF_INET;
   sa_server.sin_port = htons(nPort);
   sa_server.sin_addr = addr_local;
-
+#endif
   if (bind(server, (struct sockaddr *) &sa_server, sizeof(sa_server)) < 0)
   {
     psock_errno("bind()");
@@ -958,7 +976,11 @@
   long nTime, nResult;
   long long nData;
   int i;
+#ifdef USE_IPV6
+  struct sockaddr_in6 sa_server;
+#else
   struct sockaddr_in sa_server;
+#endif
   int server;
   int rc;
   int nByte;
@@ -969,7 +991,11 @@
     return;
   }
 
+#ifdef USE_IPV6
+  if ((server = socket(PF_INET6, SOCK_STREAM, 0)) < 0)
+#else
   if ((server = socket(PF_INET, SOCK_STREAM, 0)) < 0)
+#endif
   {
     psock_errno("socket()");
     free(cBuffer);
@@ -979,9 +1005,16 @@
   setsockopt(server, SOL_SOCKET, SO_RCVBUF, (char *) &sobufsize, sizeof(sobufsize));
   setsockopt(server, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
 
+#ifdef USE_IPV6
+  sa_server.sin6_family = AF_INET6;
+  sa_server.sin6_port = htons(nPort);
+  sa_server.sin6_addr = addr_server;
+
+#else
   sa_server.sin_family = AF_INET;
   sa_server.sin_port = htons(nPort);
   sa_server.sin_addr = addr_server;
+#endif
 
   if (connect(server, (struct sockaddr *) &sa_server, sizeof(sa_server)) < 0)
   {
@@ -1121,7 +1154,11 @@
 THREAD UDP_Receiver(void *arg)
 {
   char *cBuffer;
+#ifdef USE_IPV6
+  struct sockaddr_in6 sa_server, sa_client;
+#else
   struct sockaddr_in sa_server, sa_client;
+#endif
   int rc;
   size_t nBytes;
 
@@ -1131,7 +1168,11 @@
     return THREADRESULT;
   }
 
+#ifdef USE_IPV6
+  if ((udpsocket = socket(PF_INET6, SOCK_DGRAM, 0)) < 0)
+#else
   if ((udpsocket = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
+#endif
   {
     psock_errno("socket(DGRAM)");
     free(cBuffer);
@@ -1141,9 +1182,15 @@
   setsockopt(udpsocket, SOL_SOCKET, SO_RCVBUF, (char *) &sobufsize, sizeof(sobufsize));
   setsockopt(udpsocket, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
 
+#ifdef USE_IPV6
+  sa_server.sin6_family = AF_INET6;
+  sa_server.sin6_port = htons(nAuxPort);
+  sa_server.sin6_addr = addr_local;
+#else
   sa_server.sin_family = AF_INET;
   sa_server.sin_port = htons(nAuxPort);
   sa_server.sin_addr = addr_local;
+#endif
 
   if (bind(udpsocket, (struct sockaddr *) &sa_server, sizeof(sa_server)) < 0)
   {
@@ -1181,7 +1228,11 @@
   char *cBuffer;
   CONTROL ctl;
   long long nData;
+#ifdef USE_IPV6
+  struct sockaddr_in6 sa_server, sa_client;
+#else
   struct sockaddr_in sa_server, sa_client;
+#endif
   int server, client;
   struct timeval tv;
   fd_set fds;
@@ -1194,7 +1245,11 @@
     return THREADRESULT;
   }
 
+#ifdef USE_IPV6
+  if ((server = socket(PF_INET6, SOCK_STREAM, 0)) < 0)
+#else
   if ((server = socket(PF_INET, SOCK_STREAM, 0)) < 0)
+#endif
   {
     psock_errno("socket(STREAM)");
     free(cBuffer);
@@ -1204,9 +1259,15 @@
   setsockopt(server, SOL_SOCKET, SO_RCVBUF, (char *) &sobufsize, sizeof(sobufsize));
   setsockopt(server, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
 
+#ifdef USE_IPV6
+  sa_server.sin6_family = AF_INET6;
+  sa_server.sin6_port = htons(nAuxPort);
+  sa_server.sin6_addr = addr_local;
+#else
   sa_server.sin_family = AF_INET;
   sa_server.sin_port = htons(nAuxPort);
   sa_server.sin_addr = addr_local;
+#endif
 
   if (bind(server, (struct sockaddr *) &sa_server, sizeof(sa_server)) < 0)
   {
@@ -1252,7 +1313,11 @@
     printf("UDP connection established ... ");
     fflush(stdout);
 
+#ifdef USE_IPV6
+    sa_client.sin6_port = htons(nAuxPort);
+#else
     sa_client.sin_port = htons(nAuxPort);
+#endif
 
     for (;;)
     {
@@ -1345,7 +1410,11 @@
   long nTime, nResult, nCount;
   long long nData;
   int i;
+#ifdef USE_IPV6
+  struct sockaddr_in6 sa_server;
+#else
   struct sockaddr_in sa_server;
+#endif
   int server;
   int rc, nByte;
 
@@ -1355,7 +1424,11 @@
     return;
   }
 
+#ifdef USE_IPV6
+  if ((server = socket(PF_INET6, SOCK_STREAM, 0)) < 0)
+#else
   if ((server = socket(PF_INET, SOCK_STREAM, 0)) < 0)
+#endif
   {
     psock_errno("socket()");
     free(cBuffer);
@@ -1365,9 +1438,15 @@
   setsockopt(server, SOL_SOCKET, SO_RCVBUF, (char *) &sobufsize, sizeof(sobufsize));
   setsockopt(server, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
 
+#ifdef USE_IPV6
+  sa_server.sin6_family = AF_INET6;
+  sa_server.sin6_port = htons(nAuxPort);
+  sa_server.sin6_addr = addr_server;
+#else
   sa_server.sin_family = AF_INET;
   sa_server.sin_port = htons(nAuxPort);
   sa_server.sin_addr = addr_server;
+#endif
 
   if (connect(server, (struct sockaddr *) &sa_server, sizeof(sa_server)) < 0)
   {
@@ -1669,17 +1748,29 @@
       return psock_errno("sock_init()"), 1;
 
     if (szLocal == 0)
+#ifdef USE_IPV6
+      addr_local = in6addr_any;
+#else
       addr_local.s_addr = INADDR_ANY;
+#endif
     else
     {
       if (isdigit(*szLocal))
+#ifdef USE_IPV6
+	inet_pton(AF_INET6, szLocal, &addr_local);
+#else
 	addr_local.s_addr = inet_addr(szLocal);
+#endif
       else
       {
 	if ((host = gethostbyname(szLocal)) == NULL)
 	  return psock_errno("gethostbyname()"), 1;
 
+#ifdef USE_IPV6
+	addr_local = * (struct in6_addr *) (host->h_addr);
+#else
 	addr_local = * (struct in_addr *) (host->h_addr);
+#endif
       }
     }
 
@@ -1689,13 +1780,21 @@
 	usage();
 
       if (isdigit(*argv[optind]))
+#ifdef USE_IPV6
+	inet_pton(AF_INET6, argv[optind], &addr_server);
+#else
 	addr_server.s_addr = inet_addr(argv[optind]);
+#endif
       else
       {
 	if ((host = gethostbyname(argv[optind])) == NULL)
 	  return psock_errno("gethostbyname()"), 1;
 
+#ifdef USE_IPV6
+	addr_server = * (struct in6_addr *) (host->h_addr);
+#else
 	addr_server = * (struct in_addr *) (host->h_addr);
+#endif
       }
     }
   }

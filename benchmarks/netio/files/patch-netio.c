--- netio.c.orig	2019-03-26 20:22:31.238439000 +0100
+++ netio.c	2019-03-26 20:25:57.485700000 +0100
@@ -142,6 +142,7 @@
 #include <signal.h>
 #include <time.h>
 #if defined(UNIX) || defined(DJGPP)
+#include <arpa/inet.h>
 #include <sys/time.h>
 #include <unistd.h>
 #include <errno.h>
@@ -559,7 +560,7 @@
 
 int recv_data(int socket, void *buffer, size_t size, int flags)
 {
-  size_t rc = recv(socket, buffer, size, flags);
+  ssize_t rc = recv(socket, buffer, size, flags);
 
   if (rc < 0)
   {
@@ -576,8 +577,13 @@
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
@@ -590,7 +596,11 @@
   TIMER nTimer;
   long nTime;
   long long nData;
+#ifdef USE_IPV6
+  struct sockaddr_in6 sa_server, sa_client;
+#else
   struct sockaddr_in sa_server, sa_client;
+#endif
   int server, client;
   socklen_type length;
   struct timeval tv;
@@ -605,7 +615,11 @@
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
@@ -616,9 +630,15 @@
   setsockopt(server, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
   setsockopt(server, IPPROTO_TCP, TCP_NODELAY, (char *) &flag, sizeof(int));
 
+#ifdef USE_IPV6
+  sa_server.sin6_family = AF_INET6;
+  sa_server.sin6_port = htons(nPort);
+  sa_server.sin6_addr = addr_local;
+#else
   sa_server.sin_family = AF_INET;
   sa_server.sin_port = htons(nPort);
   sa_server.sin_addr = addr_local;
+#endif
 
   if (bind(server, (struct sockaddr *) &sa_server, sizeof(sa_server)) < 0)
   {
@@ -768,7 +788,11 @@
   long nTime;
   long long nData;
   int i;
+#ifdef USE_IPV6
+  struct sockaddr_in6 sa_server, sa_client;
+#else
   struct sockaddr_in sa_server, sa_client;
+#endif
   int server;
   int rc;
   int nByte;
@@ -780,7 +804,11 @@
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
@@ -791,9 +819,15 @@
   setsockopt(server, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
   setsockopt(server, IPPROTO_TCP, TCP_NODELAY, (char *) &flag, sizeof(int));
 
+#ifdef USE_IPV6
+  sa_client.sin6_family = AF_INET6;
+  sa_client.sin6_port = htons(0);
+  sa_client.sin6_addr = addr_local;
+#else
   sa_client.sin_family = AF_INET;
   sa_client.sin_port = htons(0);
   sa_client.sin_addr = addr_local;
+#endif
 
   if (bind(server, (struct sockaddr *) &sa_client, sizeof(sa_client)) < 0)
   {
@@ -803,9 +837,15 @@
     return;
   }
 
+#ifdef USE_IPV6
+  sa_server.sin6_family = AF_INET6;
+  sa_server.sin6_port = htons(nPort);
+  sa_server.sin6_addr = addr_server;
+#else
   sa_server.sin_family = AF_INET;
   sa_server.sin_port = htons(nPort);
   sa_server.sin_addr = addr_server;
+#endif
 
   if (connect(server, (struct sockaddr *) &sa_server, sizeof(sa_server)) < 0)
   {
@@ -928,7 +968,11 @@
 THREAD UDP_Receiver(void *arg)
 {
   char *cBuffer;
+#ifdef USE_IPV6
+  struct sockaddr_in6 sa_server, sa_client;
+#else
   struct sockaddr_in sa_server, sa_client;
+#endif
   int rc;
   socklen_type nBytes;
 
@@ -938,7 +982,11 @@
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
@@ -948,9 +996,15 @@
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
@@ -990,7 +1044,11 @@
   TIMER nTimer;
   long nTime;
   long long nData;
+#ifdef USE_IPV6
+  struct sockaddr_in6 sa_server, sa_client;
+#else
   struct sockaddr_in sa_server, sa_client;
+#endif
   int server, client;
   struct timeval tv;
   fd_set fds;
@@ -1003,7 +1061,11 @@
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
@@ -1013,9 +1075,15 @@
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
@@ -1061,7 +1129,11 @@
     printf("UDP connection established ... ");
     fflush(stdout);
 
+#ifdef USE_IPV6
+	sa_client.sin6_port = htons(nAuxPort);
+#else
     sa_client.sin_port = htons(nAuxPort);
+#endif
 
     for (;;)
     {
@@ -1177,7 +1249,11 @@
   long nResult;
   long long nData;
   int i;
+#ifdef USE_IPV6
+  struct sockaddr_in6 sa_server, sa_client;
+#else
   struct sockaddr_in sa_server, sa_client;
+#endif
   int server;
   int rc, nByte;
 
@@ -1187,7 +1263,11 @@
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
@@ -1197,9 +1277,15 @@
   setsockopt(server, SOL_SOCKET, SO_RCVBUF, (char *) &sobufsize, sizeof(sobufsize));
   setsockopt(server, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
 
+#ifdef USE_IPV6
+  sa_client.sin6_family = AF_INET6;
+  sa_client.sin6_port = htons(0);
+  sa_client.sin6_addr = addr_local;
+#else
   sa_client.sin_family = AF_INET;
-  sa_client.sin_port = htons(0);
+  sa_client.sin_port = htons(0);  
   sa_client.sin_addr = addr_local;
+#endif
 
   if (bind(server, (struct sockaddr *) &sa_client, sizeof(sa_client)) < 0)
   {
@@ -1209,9 +1295,15 @@
     return;
   }
 
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
@@ -1442,17 +1534,29 @@
       return psock_errno("sock_init()"), 1;
 
     if (szLocal == 0)
+#ifdef USE_IPV6
+	  addr_local = in6addr_any;
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
 
@@ -1462,13 +1566,21 @@
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

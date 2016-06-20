--- netio.c.orig	2016-06-20 13:21:43 UTC
+++ netio.c
@@ -136,6 +136,7 @@ static char *rcsrev = "$Revision: 1.32 $
 #include <ctype.h>
 #include <signal.h>
 #if defined(UNIX) || defined(DJGPP)
+#include <arpa/inet.h>
 #include <sys/time.h>
 #include <unistd.h>
 #include <errno.h>
@@ -546,7 +547,7 @@ int send_data(int socket, void *buffer, 
 
 int recv_data(int socket, void *buffer, size_t size, int flags)
 {
-  size_t rc = recv(socket, buffer, size, flags);
+  ssize_t rc = recv(socket, buffer, size, flags);
 
   if (rc < 0)
   {
@@ -563,8 +564,13 @@ int recv_data(int socket, void *buffer, 
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
@@ -577,7 +583,11 @@ THREAD TCP_Server(void *arg)
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
@@ -591,7 +601,11 @@ THREAD TCP_Server(void *arg)
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
@@ -601,9 +615,15 @@ THREAD TCP_Server(void *arg)
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
+#endif
 
   if (bind(server, (struct sockaddr *) &sa_server, sizeof(sa_server)) < 0)
   {
@@ -753,7 +773,11 @@ void TCP_Bench(void *arg)
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
@@ -764,7 +788,11 @@ void TCP_Bench(void *arg)
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
@@ -774,21 +802,33 @@ void TCP_Bench(void *arg)
   setsockopt(server, SOL_SOCKET, SO_RCVBUF, (char *) &sobufsize, sizeof(sobufsize));
   setsockopt(server, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
 
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
     psock_errno("bind()");
     soclose(server);
     free(cBuffer);
-    return THREADRESULT;
+    return;
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
@@ -911,7 +951,11 @@ void TCP_Bench(void *arg)
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
 
@@ -921,7 +965,11 @@ THREAD UDP_Receiver(void *arg)
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
@@ -931,9 +979,15 @@ THREAD UDP_Receiver(void *arg)
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
@@ -973,7 +1027,11 @@ THREAD UDP_Server(void *arg)
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
@@ -986,7 +1044,11 @@ THREAD UDP_Server(void *arg)
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
@@ -996,9 +1058,15 @@ THREAD UDP_Server(void *arg)
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
@@ -1044,7 +1112,11 @@ THREAD UDP_Server(void *arg)
     printf("UDP connection established ... ");
     fflush(stdout);
 
+#ifdef USE_IPV6
+	sa_client.sin6_port = htons(nAuxPort);
+#else
     sa_client.sin_port = htons(nAuxPort);
+#endif
 
     for (;;)
     {
@@ -1160,7 +1232,11 @@ void UDP_Bench(void *arg)
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
 
@@ -1170,7 +1246,11 @@ void UDP_Bench(void *arg)
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
@@ -1180,21 +1260,33 @@ void UDP_Bench(void *arg)
   setsockopt(server, SOL_SOCKET, SO_RCVBUF, (char *) &sobufsize, sizeof(sobufsize));
   setsockopt(server, SOL_SOCKET, SO_SNDBUF, (char *) &sobufsize, sizeof(sobufsize));
 
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
     psock_errno("bind(STREAM)");
     soclose(server);
     free(cBuffer);
-    return THREADRESULT;
+    return;
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
@@ -1425,17 +1517,29 @@ int main(int argc, char **argv)
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
 
@@ -1445,13 +1549,21 @@ int main(int argc, char **argv)
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

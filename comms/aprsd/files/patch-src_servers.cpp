--- src/servers.cpp.orig	2003-10-01 16:58:27 UTC
+++ src/servers.cpp
@@ -2283,7 +2283,7 @@ void *TCPServerThread(void *p)
     server.sin_addr.s_addr = INADDR_ANY;
     server.sin_port = htons(sp->ServerPort);
 
-    if (bind(s, (struct sockaddr *)&server, sizeof(server)) <  0) {
+    if (::bind(s, (struct sockaddr *)&server, sizeof(server)) <  0) {
         perror("TCPServerThread bind error");
         ShutDownServer = true;
         return NULL;
@@ -2382,7 +2382,7 @@ void *UDPServerThread(void *p)
     server.sin_port = htons(UDP_Port) ;/* 0 = Use any available port       */
     server.sin_addr.s_addr = INADDR_ANY;	/* Server's Internet Address    */
 
-    if (bind(s, (struct sockaddr *)&server, sizeof(server)) < 0) {
+    if (::bind(s, (struct sockaddr *)&server, sizeof(server)) < 0) {
         perror("Datagram socket bind error");
         ShutDownServer = true;
         return NULL;

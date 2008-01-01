--- skkserv/skkserv.c.orig	2008-01-01 20:00:27.000000000 +0100
+++ skkserv/skkserv.c	2008-01-01 20:01:01.000000000 +0100
@@ -476,7 +476,7 @@
 
     if (FD_ISSET(initsock, &readfds)) {
       len = sizeof(from);
-      if ((clientsock[nclients ++] = accept(initsock, &from, &len)) < 0) {
+      if ((clientsock[nclients ++] = accept(initsock, (struct sockaddr*)&from, &len)) < 0) {
 	err("accept error; something wrong happened with the socket");
       }
       if (nclients >= MAXDTAB - 3 - debug * 2) {

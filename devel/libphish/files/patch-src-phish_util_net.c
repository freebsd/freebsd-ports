--- src/phish_util_net.c.orig	Mon Mar 20 09:54:25 2006
+++ src/phish_util_net.c	Mon Jun  5 13:40:14 2006
@@ -30,6 +30,8 @@
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netdb.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #endif
 
 #include "phish.h"
@@ -72,7 +74,7 @@
   h->ent = NULL;
   h->buf = NULL;
   
-#ifdef WIN32
+#if defined(WIN32) || defined(FreeBSD)
 
   h->ent = gethostbyname(name);
   

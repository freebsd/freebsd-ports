--- src/connect.c.orig	Fri Aug 17 20:38:25 2001
+++ src/connect.c	Sat Jan 25 19:38:06 2003
@@ -27,6 +27,7 @@
 #include <sys/socket.h>
 #include <fcntl.h>
 #include <netdb.h>
+#include <netinet/in_systm.h>
 #include <netinet/in.h>
 #include <netinet/ip.h>
 #include <netdb.h>
@@ -341,6 +342,8 @@
     struct hostent *hp;
     int herr,res;
 
+#ifndef __FreeBSD__
+
     if (*hstbuflen == 0)
     {
 	*hstbuflen = 2048; 
@@ -364,5 +367,9 @@
 	}
     if (res)
 	return NULL;
+#else
+	hp = gethostbyname(host);
+#endif
+
     return hp;
 }

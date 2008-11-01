--- lib/imlib/imxport.c.orig	2002-10-03 18:35:31.000000000 +0900
+++ lib/imlib/imxport.c	2008-11-02 01:23:56.000000000 +0900
@@ -35,6 +35,7 @@
 
 #ifdef IM_TCP_TRANSPORT
 #include <netinet/in.h> 
+#include <netdb.h>
 #endif
 
 extern int errno;
@@ -412,8 +413,9 @@
 
 #ifdef IM_TCP_TRANSPORT
 int
-IMCreateTCPService(portp)
+IMCreateTCPService(portp, listenaddr)
 int *portp;
+char *listenaddr;
 {
     struct sockaddr_in addr;
     int optval = 1;
@@ -431,7 +433,22 @@
 		     (char *)&optval, sizeof(optval));
 #endif /* SO_REUSEADDR */
 
-    bzero((char *)&addr, sizeof(addr));
+    memset((void *)&addr, 0, sizeof(addr));
+    if (listenaddr[0] == '\0') {
+	    addr.sin_addr.s_addr = htonl(INADDR_ANY);
+    } else {
+	    if (!inet_aton(listenaddr, &addr.sin_addr)) {
+		    struct hostent  *hp;
+		    struct in_addr  **pptr;
+
+		    if ((hp = gethostbyname((const char *)listenaddr)) == NULL) {
+			    DPRINT(("Can't resolve %s\n", listenaddr));
+			    return -1;
+		    }
+		    pptr = (struct in_addr **)hp->h_addr_list;
+		    memcpy((void *)&addr.sin_addr, pptr[0], sizeof(struct in_addr));
+	    }
+    }
     addr.sin_family = AF_INET;
     addr.sin_port = htons(*portp);
 

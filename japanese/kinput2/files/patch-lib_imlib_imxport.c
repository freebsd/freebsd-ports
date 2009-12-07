Index: lib/imlib/imxport.c
===================================================================
RCS file: /home/cvs/private/hrs/kinput2/lib/imlib/imxport.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- lib/imlib/imxport.c	7 Dec 2009 06:36:04 -0000	1.1.1.1
+++ lib/imlib/imxport.c	7 Dec 2009 06:44:58 -0000	1.2
@@ -31,10 +31,12 @@ static char *rcsid = "$Id: imxport.c,v 1
 
 #ifdef IM_UNIX_TRANSPORT
 #include <sys/un.h>
+#include <sys/stat.h>
 #endif
 
 #ifdef IM_TCP_TRANSPORT
 #include <netinet/in.h> 
+#include <netdb.h>
 #endif
 
 extern int errno;
@@ -412,8 +414,9 @@ IMConnection *conn;
 
 #ifdef IM_TCP_TRANSPORT
 int
-IMCreateTCPService(portp)
+IMCreateTCPService(portp, listenaddr)
 int *portp;
+char *listenaddr;
 {
     struct sockaddr_in addr;
     int optval = 1;
@@ -431,7 +434,22 @@ int *portp;
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
 
@@ -495,6 +513,7 @@ char *path;
 {
     struct sockaddr_un addr;
     int sock;
+    mode_t oldumask;
 
     TRACE(("IMCreateUnixService(%s)\n", path));
     if ((sock = socket(PF_UNIX, SOCK_STREAM, 0)) < 0) {
@@ -510,15 +529,21 @@ char *path;
      * Remove socket which is created by the previous process.
      */
     (void)unlink(path);
+    oldumask = umask(S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH|S_IWOTH|S_IXOTH);
 
     if (bind(sock, (struct sockaddr *)&addr, strlen(path) + 2) < 0) {
 	DPRINT(("bind() failed with %d\n", errno));
+	umask(oldumask);
 	return -1;
     }
+
+    umask(oldumask);
+	
     if (listen(sock, 4) < 0) {
 	DPRINT(("listen() failed with %d\n", errno));
 	return -1;
     }
+
     return sock;
 }
 

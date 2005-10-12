--- src/connect.c.orig	Sat Feb 26 16:47:17 2005
+++ src/connect.c	Sun Oct  9 13:06:34 2005
@@ -24,9 +24,11 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <fcntl.h>
 #include <netdb.h>
+#include <netinet/in_systm.h>
 #include <netinet/in.h>
 #include <netinet/ip.h>
 #include <netdb.h>
@@ -42,53 +44,52 @@
 #include "runtime.h"
 #include "debug.h"
 
+static pthread_mutex_t __thread_safe_lock  = PTHREAD_MUTEX_INITIALIZER;
+
 uerr_t connect_to_server(int *sock, char *name, int port, int timeout)
 {
-    unsigned int portnum;
+    char szPort[10];
     int status;
-    struct sockaddr_in server;
-    struct hostent *hp, hostbuf;
     extern int h_errno;
     /*    int opt; */
     int noblock, flags;
 
-    char *tmphstbuf;
-    size_t hstbuflen = 2048;
-    tmphstbuf = kmalloc(hstbuflen);
+    struct addrinfo hints, *res=NULL;
+    struct addrinfo *res0=NULL;
+    int error;
 
     assert(name != NULL);
 
-    portnum = port;
-    memset((void *) &server, 0, sizeof(server));
+    memset(&hints, 0, sizeof(hints));
+    memset(szPort, 0, sizeof(szPort));
+    snprintf(szPort, sizeof(szPort), "%d", port);
+    hints.ai_family = AF_INET;
+    hints.ai_socktype = SOCK_STREAM;
 
     message("Resolving %s", name);
 
-    hp=k_gethostname (name,&hostbuf,&tmphstbuf,&hstbuflen);
-
-    if (hp == NULL)
-    {
-	message("Failed to resolve %s", name);
-	return HOSTERR;
-    }
+    error = getaddrinfo(name, szPort, &hints, &res);
+    if (error) {
+            message("Failed to resolve %s", name);
+            pthread_mutex_unlock(&__thread_safe_lock); 
+            freeaddrinfo(res);
+            return HOSTERR;
+        }
 
     message("Resolved %s !", name);
-    
-    memcpy((void *) &server.sin_addr, hp->h_addr, hp->h_length);
-    server.sin_family = hp->h_addrtype;
-    server.sin_port = htons(portnum);
 
-    if (tmphstbuf)
-    {
-	free(tmphstbuf);
-	tmphstbuf = NULL;
-    }
+    res0 = (struct addrinfo *) malloc(sizeof(struct addrinfo));
+    memcpy(res0, res, sizeof(struct addrinfo));
+    freeaddrinfo(res);
+    pthread_mutex_unlock(&__thread_safe_lock);
 
     /*
      * create socket 
      */
-    if ((*sock = socket(AF_INET, SOCK_STREAM, 0)) < 1)
+    if ((*sock = socket(res0->ai_family, res0->ai_socktype, 0)) < 1)
     {
 	message("unable to create socket\n");
+	free(res0);
 	return CONSOCKERR;
     }
     /*Experimental */
@@ -100,8 +101,7 @@
 
     message("Connecting to server.......");
 
-
-    status = connect(*sock, (struct sockaddr *) &server, sizeof(server));
+    status = connect(*sock, res0->ai_addr, res0->ai_addrlen);
 
     if (status == -1 && noblock != -1 && errno == EINPROGRESS)
     {
@@ -137,10 +137,13 @@
     {
 	close(*sock);
 
-	if (errno == ECONNREFUSED)
+	if (errno == ECONNREFUSED) {
+	    free(res0);
 	    return CONREFUSED;
-	else
+	} else {
+	    free(res0);
 	    return CONERROR;
+	}
     } else
     {
 	flags = fcntl(*sock, F_GETFL, 0);
@@ -156,6 +159,7 @@
      *         (char *) &opt, (int) sizeof(opt));  
      */
     message("Connect OK!");
+    free(res0);
     return NOCONERROR;
 }
 

--- src/server.c.orig	Thu Jan 26 16:00:28 2006
+++ src/server.c	Mon Jan 22 20:13:09 2007
@@ -342,7 +342,8 @@
 	lo_method next;
 
 	if (s->socket != -1) close(s->socket);
-	freeaddrinfo(s->ai);
+	if (s->ai)
+	    freeaddrinfo(s->ai);
 	free(s->hostname);
 	free(s->path);
 	for (it = s->first; it; it = next) {
@@ -639,38 +640,11 @@
 
     //inet_ntop(s->addr.ss_family, &s->addr.padding, hostname, sizeof(hostname));
     if (s->protocol == LO_UDP) {
-	err = getnameinfo((struct sockaddr *)&s->addr, sizeof(s->addr),
+	err = getnameinfo((struct sockaddr *)&s->addr, s->addr.ss_len,
 	    hostname, sizeof(hostname), portname, sizeof(portname),
 	    NI_NUMERICHOST | NI_NUMERICSERV);
 	if (err) {
-	    switch (err) {
-	    case EAI_AGAIN:
-		lo_throw(s, err, "Try again", path);
-		break;
-	    case EAI_BADFLAGS:
-		lo_throw(s, err, "Bad flags", path);
-		break;
-	    case EAI_FAIL:
-		lo_throw(s, err, "Failed", path);
-		break;
-	    case EAI_FAMILY:
-		lo_throw(s, err, "Cannot resolve address family", path);
-		break;
-	    case EAI_MEMORY:
-		lo_throw(s, err, "Out of memory", path);
-		break;
-	    case EAI_NONAME:
-		lo_throw(s, err, "Cannot resolve", path);
-		break;
-#ifndef WIN32
-	    case EAI_SYSTEM:
-		lo_throw(s, err, strerror(err), path);
-		break;
-#endif
-	    default:
-		lo_throw(s, err, "Unknown error", path);
-		break;
-	    }
+	    lo_throw(s, err, gai_strerror(err), path);
 
 	    return;
 	}

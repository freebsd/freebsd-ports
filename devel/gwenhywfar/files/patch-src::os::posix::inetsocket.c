# $FreeBSD$
--- src/os/posix/inetsocket.c.orig	2008-07-31 10:56:06.000000000 -0700
+++ src/os/posix/inetsocket.c	2009-07-12 09:59:23.000000000 -0700
@@ -74,6 +74,7 @@
 int GWEN_Socket_NetError2GwenError(int rv) {
   switch(rv) {
   case EINTR:        return GWEN_ERROR_INTERRUPTED;
+  case ENOTCONN:
   case EWOULDBLOCK:  return GWEN_ERROR_TIMEOUT;
   case EACCES:
   case EPERM:        return GWEN_ERROR_PERMISSIONS;
@@ -348,7 +349,7 @@
   if (localSocket->socket==-1) {
     GWEN_InetAddr_free(localAddr);
     GWEN_Socket_free(localSocket);
-    if (errno==EAGAIN)
+    if (errno==EAGAIN || errno==ENOTCONN)
       return GWEN_ERROR_TIMEOUT;
     else {
       DBG_INFO(GWEN_LOGDOMAIN, "accept(): %s", strerror(errno));
@@ -498,7 +499,7 @@
   assert(bsize);
   i=recv(sp->socket,buffer, *bsize,0);
   if (i<0) {
-    if (errno==EAGAIN)
+    if (errno==EAGAIN || errno==ENOTCONN)
       return GWEN_ERROR_TIMEOUT;
     else if (errno==EINTR)
       return GWEN_ERROR_INTERRUPTED;
@@ -542,7 +543,7 @@
 	);
 
   if (i<0) {
-    if (errno==EAGAIN)
+    if (errno==EAGAIN || errno==ENOTCONN)
       return GWEN_ERROR_TIMEOUT;
     else if (errno==EINTR)
       return GWEN_ERROR_INTERRUPTED;
@@ -594,7 +595,7 @@
              &addrlen);
   if (i<0) {
     GWEN_InetAddr_free(localAddr);
-    if (errno==EAGAIN)
+    if (errno==EAGAIN || errno==ENOTCONN)
       return GWEN_ERROR_TIMEOUT;
     else if (errno==EINTR)
       return GWEN_ERROR_INTERRUPTED;
@@ -632,7 +633,7 @@
            addr->address,
            addr->size);
   if (i<0) {
-    if (errno==EAGAIN)
+    if (errno==EAGAIN || errno==ENOTCONN)
       return GWEN_ERROR_TIMEOUT;
     else if (errno==EINTR)
       return GWEN_ERROR_INTERRUPTED;

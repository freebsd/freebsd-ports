--- Src/pathchirp_rcv.h.orig	2005-05-20 15:42:05 UTC
+++ Src/pathchirp_rcv.h
@@ -37,11 +37,7 @@ extern FILE *fd_debug;/* file pointers for debug files
 
 #ifdef HAVE_SO_TIMESTAMP
 extern struct  msghdr msg;
 extern   struct  iovec iov[1];
-   union{
-     struct cmsghdr cm;
-     char control[CMSG_SPACE(sizeof(struct timeval))];
-   } control_un;
 
 extern   struct cmsghdr *cmptr;
 #endif

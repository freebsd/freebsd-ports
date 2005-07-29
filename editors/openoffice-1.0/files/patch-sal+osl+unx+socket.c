--- sal/osl/unx/socket.c.orig	Sun Mar 17 12:46:37 2002
+++ sal/osl/unx/socket.c	Wed Apr  3 01:01:14 2002
@@ -82,7 +82,7 @@
 #undef HAVE_POLL_H
 #endif
 
-#if defined(LINUX) || defined (IRIX) || defined(NETBSD)
+#if defined(LINUX) || defined (IRIX) || defined(NETBSD) || defined(FREEBSD)
 #include <sys/poll.h>
 #define HAVE_POLL_H
 #endif /* HAVE_POLL_H */
@@ -1965,7 +1965,7 @@
 /*****************************************************************************/
 oslSocketAddr SAL_CALL osl_getLocalAddrOfSocket(oslSocket pSocket)
 {
-#ifdef LINUX
+#ifdef LINUX || defined(FREEBSD)
 	socklen_t AddrLen;
 #else
 	/* mfe: Solaris 'cc +w' means Addrlen should be signed! */

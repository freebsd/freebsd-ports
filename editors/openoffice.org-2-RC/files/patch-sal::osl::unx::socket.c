--- ../sal/osl/unx/socket.c.orig	Fri Jun 22 16:22:14 2001
+++ ../sal/osl/unx/socket.c	Sun Mar 10 23:33:56 2002
@@ -82,7 +82,7 @@
 #undef HAVE_POLL_H
 #endif
 
-#if defined(LINUX) || defined (IRIX)
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

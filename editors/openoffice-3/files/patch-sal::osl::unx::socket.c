--- ../sal/osl/unx/socket.c.orig	Tue Apr  9 20:09:53 2002
+++ ../sal/osl/unx/socket.c	Fri Oct 18 20:00:19 2002
@@ -82,12 +82,12 @@
 #undef HAVE_POLL_H
 #endif
 
-#if defined(LINUX) || defined (IRIX) || defined(NETBSD)
+#if defined(LINUX) || defined (IRIX) || defined(NETBSD) || defined ( FREEBSD )
 #include <sys/poll.h>
 #define HAVE_POLL_H
 #endif /* HAVE_POLL_H */
 
-#if defined(SOLARIS) || defined ( FREEBSD )
+#if defined(SOLARIS)
 #include <poll.h>
 #define HAVE_POLL_H
 #endif /* SOLARIS */
@@ -1965,7 +1965,7 @@
 /*****************************************************************************/
 oslSocketAddr SAL_CALL osl_getLocalAddrOfSocket(oslSocket pSocket)
 {
-#ifdef LINUX
+#ifdef LINUX || defined(FREEBSD)
 	socklen_t AddrLen;
 #else
 	/* mfe: Solaris 'cc +w' means Addrlen should be signed! */

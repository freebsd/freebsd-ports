--- ../sal/osl/unx/socket.c.orig	Sun Mar  3 18:12:48 2002
+++ ../sal/osl/unx/socket.c	Sun Mar  3 18:16:32 2002
@@ -82,7 +82,7 @@
 #undef HAVE_POLL_H
 #endif
 
-#if defined(LINUX) || defined (IRIX)
+#if defined(LINUX) || defined (IRIX) || defined(NETBSD) || defined(FREEBSD)
 #include <sys/poll.h>
 #define HAVE_POLL_H
 #endif /* HAVE_POLL_H */

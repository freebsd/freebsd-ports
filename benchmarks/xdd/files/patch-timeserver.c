--- timeserver.c.orig	Mon May 29 04:25:26 2006
+++ timeserver.c	Mon May 29 04:25:56 2006
@@ -29,9 +29,9 @@
 #include <stdarg.h> /* variable arguments stuff */
 #include <string.h> /* strrchr(), strerror() */
 #include <errno.h> /* errno stuff */
-#if (IRIX || SOLARIS || AIX || HPUX || LINUX || OSX)
+#if (IRIX || SOLARIS || AIX || HPUX || LINUX || OSX || FreeBSD)
 #include <unistd.h>
-#if !(SOLARIS || AIX || HPUX || LINUX || OSX)
+#if !(SOLARIS || AIX || HPUX || LINUX || OSX || FreeBSD)
 #include <bstring.h>
 #endif
 #include <limits.h> /* USHRT_MAX */
@@ -57,7 +57,7 @@
 /* ----- */
 /* Types */
 /* ----- */
-#if !(IRIX || SOLARIS || AIX || HPUX || LINUX || OSX)
+#if !(IRIX || SOLARIS || AIX || HPUX || LINUX || OSX || FreeBSD)
 /* SGI defines these in <netinet/in.h> */
 typedef unsigned long in_addr_t; /* An IP number */
 typedef unsigned short in_port_t; /* A port number */
@@ -231,7 +231,7 @@
 #if (AIX)
     nd = sd + 1;
 #endif
-#if (SOLARIS || HPUX || OSX)
+#if (SOLARIS || HPUX || OSX || FreeBSD)
 	nd = FD_SETSIZE;
 #endif
     for (;;) {

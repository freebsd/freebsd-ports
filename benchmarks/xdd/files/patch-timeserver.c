--- timeserver.c.orig	Fri Mar 16 07:13:50 2007
+++ timeserver.c	Fri Mar 16 07:14:38 2007
@@ -30,9 +30,9 @@
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
@@ -58,7 +58,7 @@
 /* ----- */
 /* Types */
 /* ----- */
-#if !(IRIX || SOLARIS || AIX || HPUX || LINUX || OSX)
+#if !(IRIX || SOLARIS || AIX || HPUX || LINUX || OSX || FreeBSD)
 /* SGI defines these in <netinet/in.h> */
 typedef unsigned long in_addr_t; /* An IP number */
 typedef unsigned short in_port_t; /* A port number */
@@ -225,7 +225,7 @@
 #if (IRIX || WIN32)
     nd = getdtablehi();
 #endif
-#if (LINUX || OSX)
+#if (LINUX || OSX || FreeBSD)
     nd = getdtablesize();
 #endif
 #if (AIX)

--- misc.c.orig	Sun Mar 14 00:00:00 1999
+++ misc.c	Sun Feb 13 15:55:51 2000
@@ -1188,7 +1188,11 @@
 				pb = pbuf + strlen(pbuf) - 5;
 #endif
 #if defined(_T_MSDOS) || defined(_T_UNIX)
+#ifndef __FreeBSD__
 				sprintf(pbuf, "%05d", getpid());
+#else
+				sprintf(pbuf, "%05ld", getpid());
+#endif
 				pb = pbuf;
 #endif
 #if defined(_T_WIN32CONSOLE) || defined(_T_WINDOWS)

--- src/gl/system.c.orig	Tue Jul 17 23:58:43 2001
+++ src/gl/system.c	Wed Jul 18 00:00:29 2001
@@ -69,7 +69,7 @@
 	 "/usr/openwin/contrib/bin", "/Window/X11/bin",
 	 "/Window/X11/contrib/bin", 0};
 
-#if defined(LINUX) || defined(AIX) || defined(HPUX) || defined(OSF1)
+#if defined(BSD)
 typedef void (*SIG_PF)(int);
 #endif
 

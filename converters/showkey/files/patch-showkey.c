$FreeBSD$

--- showkey.c.orig	Tue Aug 27 03:12:48 2002
+++ showkey.c	Fri Oct 24 01:02:04 2003
@@ -58,7 +58,7 @@
     unsigned char	c;
     unsigned int	i, timeouts;
 
-    for (i = SIGHUP; i <= SIGPOLL; i++)
+    for (i = SIGHUP; i <= SIGIO; i++)
 	(void) signal(c, catcher);
 
     // Get the state of the tty 

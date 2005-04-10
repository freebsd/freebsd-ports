--- plug-ins/common/url.c.orig	Mon Mar 14 05:00:40 2005
+++ plug-ins/common/url.c	Sun Apr 10 11:45:50 2005
@@ -186,8 +186,8 @@
       putenv ("LANG=C");
 #endif
 
-      execlp ("wget", "wget", "-e", "server-response=off", "-T", TIMEOUT,
-              filename, "-O", tmpname, NULL);
+      execlp ("fetch", "fetch", "-T", TIMEOUT, filename, "-p", "-o", 
+              tmpname, NULL);
       g_message ("exec() failed: wget: %s", g_strerror (errno));
       g_free (tmpname);
       _exit (127);

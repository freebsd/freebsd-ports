--- plug-ins/common/url.c.orig	Wed Dec 28 13:56:48 2005
+++ plug-ins/common/url.c	Wed Dec 28 13:58:33 2005
@@ -186,10 +186,10 @@
       putenv ("LANG=C");
 #endif
 
-      execlp ("wget",
-              "wget", "-v", "-e", "server-response=off", "-T", TIMEOUT,
-              filename, "-O", tmpname, NULL);
-      g_message ("exec() failed: wget: %s", g_strerror (errno));
+      execlp ("fetch",
+              "fetch", "-T", TIMEOUT,
+              filename, "-p", "-o", tmpname, NULL);
+      g_message ("exec() failed: fetch: %s", g_strerror (errno));
       g_free (tmpname);
       _exit (127);
     }

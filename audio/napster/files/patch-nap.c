--- nap.c.orig	Fri Mar  1 11:17:37 2002
+++ nap.c	Sat Mar  9 17:24:26 2002
@@ -1987,7 +1987,7 @@
   char *buf;
   char *p;
   int i, r;
-  int timeout;
+  int timeout, on = 1;
 
   timeout = nvar_default("connecttimeout", CONNECTTIMEOUT);
 
@@ -2010,6 +2010,10 @@
       wp(wchan, "Error creating socket: %s\n", strerror(errno));
       drw(wchan);
       return(-1);
+    }
+
+    if (setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == -1) {
+      perror("setsockopt(SO_REUSEADDR)");
     }
     
     if (connect_t(s, (struct sockaddr *)&dst, sizeof(dst), timeout) == -1) {

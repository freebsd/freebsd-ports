--- client.c.orig	Sat May  2 11:11:26 1998
+++ client.c	Sat May  3 20:13:18 2003
@@ -718,7 +718,7 @@
 #	ifndef ESPX
 #	ifndef WIN32
 #	ifndef linux
-  unsigned long inet_addr();
+  in_addr_t inet_addr();
 #	endif /* (!linux) */
 #	endif /* (!WIN32) */
 #	endif /* (!ESPX) */

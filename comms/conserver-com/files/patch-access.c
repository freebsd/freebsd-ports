--- conserver/access.c.orig	Mon Jan 21 19:48:49 2002
+++ conserver/access.c	Wed Feb 27 10:19:12 2002
@@ -117,7 +117,7 @@
     netmask = htonl(netmask);
     if (~netmask & pattern_addr)
 	netmask = 0xffffffff;	/* compare entire addresses */
-    hostaddr = *(unsigned long int *)addr;
+    hostaddr = *(unsigned int *)addr;
 
     Debug("Access check:       host=%lx(%lx/%lx)", hostaddr & netmask,
 	  hostaddr, netmask);

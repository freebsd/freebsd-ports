--- src/dcc_net.c.orig	2007-10-02 13:31:06.000000000 +0200
+++ src/dcc_net.c	2007-10-02 13:31:27.000000000 +0200
@@ -364,7 +364,7 @@
       n = p->next;
       _dccnet_free(p);
 
-      p = (l ? l->next : proxies) = n;
+      p = *(l ? &(l->next) : &(proxies)) = n;
     } else {
       l = p;
       p = p->next;

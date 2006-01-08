--- iflist.c.orig	Sun Jan  8 08:18:32 2006
+++ iflist.c	Sun Jan  8 08:18:36 2006
@@ -184,7 +184,7 @@
     c->thr_ifcb = callback;
     c->thr_data = data;
 
-    return THR_CREATE(ifaces_r, c);
+    return (int)THR_CREATE(ifaces_r, c);
 }
 
 /**

--- src/lgc.c.orig	2016-12-22 13:08:50 UTC
+++ src/lgc.c
@@ -643,8 +643,9 @@ static void clearkeys (global_State *g, GCObject *l, G
     for (n = gnode(h, 0); n < limit; n++) {
       if (!ttisnil(gval(n)) && (iscleared(g, gkey(n)))) {
         setnilvalue(gval(n));  /* remove value ... */
-        removeentry(n);  /* and remove entry from table */
       }
+      if (ttisnil(gval(n)))  /* is entry empty? */
+        removeentry(n);  /* remove entry from table */
     }
   }
 }

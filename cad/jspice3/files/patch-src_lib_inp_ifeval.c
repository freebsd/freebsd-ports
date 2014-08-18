--- src/lib/inp/ifeval.c.orig	1997-03-21 22:04:12.000000000 +0000
+++ src/lib/inp/ifeval.c
@@ -37,7 +37,7 @@ double step, finaltime;
     int i;
 
     if (!tree)
-        return;
+        return (OK);
     for (i = 0; i < tree->numVars; i++)
         init_node(pt->derivs[i],step,finaltime);
     init_node(pt->tree,step,finaltime);

--- src/lib/plot/postsc.c.orig	1997-03-21 22:03:37.000000000 +0000
+++ src/lib/plot/postsc.c
@@ -343,12 +343,12 @@ int linestyleid;
         get it when PS_Text restores a -1 linestyle */
     if (linestyleid == -1) {
         currentgraph->linestyle = -1;
-        return;
+        return (0);
     }
 
     if (linestyleid < 0) {
         internalerror("bad linestyleid");
-        return;
+        return (0);
     }
 
     if (linestyleid > dispdev->numlinestyles)
@@ -407,7 +407,7 @@ int x, y, Xform;
 
     if (Xform == (char)0) {
         PS_Text(text,x,y);
-        return;
+        return (0);
     }
 
     s = tbuf;

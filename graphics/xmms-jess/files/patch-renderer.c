
$FreeBSD$

--- renderer.c.orig	Sun Aug 22 17:52:50 2004
+++ renderer.c	Sun Aug 22 17:52:59 2004
@@ -93,7 +93,7 @@
 		     conteur.angle2 / 60, 200, 130);
       break;
 
-    default:
+    default: break;
     }
 
   conteur.k3 += 10;

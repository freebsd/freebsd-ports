
$FreeBSD$

--- render.c.orig	Sun Aug 22 15:27:18 2004
+++ render.c	Sun Aug 22 15:27:28 2004
@@ -148,7 +148,7 @@
 	exit(1);
       }
       break;
-    default:
+    default: break;
     }
   } else {
     if (p->ncolors > 256) {


$FreeBSD$

--- src/pcISel.c.orig	Sun Aug 22 23:21:11 2004
+++ src/pcISel.c	Sun Aug 22 23:21:23 2004
@@ -540,7 +540,7 @@
 		    break;
 	    }
 	}
-      next:
+      next: break;
     }
 
     if (currTbl)

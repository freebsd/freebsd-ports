
$FreeBSD$

--- src/buildmap_range.c.orig	Sun Aug 22 16:58:03 2004
+++ src/buildmap_range.c	Sun Aug 22 16:58:18 2004
@@ -889,7 +889,8 @@
       }
 
       next_square:
-   }
+    break;
+  }
 
 
    square_current = -1;


$FreeBSD$

--- image.c.orig	Sun Aug 22 15:26:48 2004
+++ image.c	Sun Aug 22 15:26:58 2004
@@ -292,7 +292,7 @@
     default:
       fprintf(stderr, "Unimplemented method: %d to %d\n", p->type, to);
     }
-  default:
+  default: break;
     /* ignored */
   }
 

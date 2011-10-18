--- lib-hiredis.c.orig	2011-09-15 21:20:51.536376311 +0200
+++ lib-hiredis.c	2011-09-15 21:21:07.683644231 +0200
@@ -693,7 +693,7 @@
                     }
 
                     /* Consume and discard vararg */
-                    va_arg(ap,void);
+                    va_arg(ap,void*);
                 }
             }
             c++;
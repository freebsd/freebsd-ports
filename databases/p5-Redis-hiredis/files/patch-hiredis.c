--- hiredis.c.orig	2012-04-12 09:01:52.000000000 +0200
+++ hiredis.c	2012-04-12 09:02:01.000000000 +0200
@@ -796,7 +796,7 @@
                     }
 
                     /* Consume and discard vararg */
-                    va_arg(ap,void);
+                    va_arg(ap,void*);
                 }
             }
 

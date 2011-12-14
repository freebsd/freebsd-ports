--- deps/hiredis/hiredis.c.orig	2011-11-23 15:42:15.000000000 +0400
+++ deps/hiredis/hiredis.c	2011-11-23 15:42:45.000000000 +0400
@@ -697,7 +697,7 @@
                     }
 
                     /* Consume and discard vararg */
-                    va_arg(ap,void);
+                    va_arg(ap,void*);
                 }
             }
             touched = 1;

--- hiredis.c.orig	2011-09-16 15:11:57.000000000 +0800
+++ hiredis.c	2011-09-16 15:12:19.000000000 +0800
@@ -796,7 +796,7 @@ int redisvFormatCommand(char **target, c
                     }
 
                     /* Consume and discard vararg */
-                    va_arg(ap,void);
+                    va_arg(ap, void*);
                 }
             }
 

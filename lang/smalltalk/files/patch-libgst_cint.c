--- libgst/cint.c.orig	2013-04-29 23:42:00.000000000 +0200
+++ libgst/cint.c	2013-04-29 23:42:10.000000000 +0200
@@ -399,6 +399,7 @@ my_putenv (const char *str)
 static char **
 get_environ (void)
 {
+  extern char **environ;
   return environ;
 }
 

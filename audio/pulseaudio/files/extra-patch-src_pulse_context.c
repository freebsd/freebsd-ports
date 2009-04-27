--- src/pulse/context.c.orig	2009-03-08 14:33:36.000000000 -0400
+++ src/pulse/context.c	2009-03-08 14:33:42.000000000 -0400
@@ -664,7 +664,7 @@ static int context_autospawn(pa_context 
         n = 0;
 
         argv[n++] = c->conf->daemon_binary;
-        argv[n++] = "--start";
+        argv[n++] = "-D";
 
         while (n < MAX_ARGS) {
             char *a;

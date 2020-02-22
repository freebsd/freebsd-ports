--- src/bin/proc2mod.c.orig	1992-09-17 12:33:34 UTC
+++ src/bin/proc2mod.c
@@ -51,7 +51,7 @@ FILE *p = NULL;
 char *dataline;
 
 
-void
+int
 main() {
     char *typeline;
     char *prname;

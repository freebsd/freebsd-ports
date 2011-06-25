--- src/bin/proc2mod.c.orig	2011-06-24 16:07:41.000000000 +0000
+++ src/bin/proc2mod.c	2011-06-24 16:08:43.000000000 +0000
@@ -51,7 +51,7 @@
 char *dataline;
 
 
-void
+int
 main() {
     char *typeline;
     char *prname;

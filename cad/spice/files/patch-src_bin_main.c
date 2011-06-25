--- src/bin/main.c.orig	2011-06-24 16:53:54.000000000 +0000
+++ src/bin/main.c	2011-06-24 16:54:24.000000000 +0000
@@ -183,7 +183,7 @@
 
 char *hlp_filelist[] = { "spice", 0 };
 
-void
+int
 main(ac, av)
     char **av;
 {

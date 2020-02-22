--- src/bin/main.c.orig	1993-07-29 05:48:32 UTC
+++ src/bin/main.c
@@ -183,7 +183,7 @@ if_tranparams(ckt, start, stop, step) struct circ *ckt
 
 char *hlp_filelist[] = { "spice", 0 };
 
-void
+int
 main(ac, av)
     char **av;
 {

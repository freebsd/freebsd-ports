--- src/bin/help.c.orig	1993-04-22 00:35:08 UTC
+++ src/bin/help.c
@@ -46,7 +46,7 @@ bool cp_interactive = false;
 char *hlp_filelist[] = { "spice", 0 };
 
 /* ARGSUSED */
-void
+int
 main(ac, av)
     int ac;
     char **av;

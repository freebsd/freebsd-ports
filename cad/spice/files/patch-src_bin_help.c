--- src/bin/help.c.orig	2011-06-24 19:12:52.000000000 +0000
+++ src/bin/help.c	2011-06-24 19:13:19.000000000 +0000
@@ -46,7 +46,7 @@
 char *hlp_filelist[] = { "spice", 0 };
 
 /* ARGSUSED */
-void
+int
 main(ac, av)
     int ac;
     char **av;

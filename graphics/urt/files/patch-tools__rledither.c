--- tools/rledither.c.orig	1992-01-24 01:42:22.000000000 +0900
+++ tools/rledither.c	2012-10-15 22:52:09.000000000 +0900
@@ -47,7 +47,7 @@
 
 char *progname;
 
-void
+int
 main(argc, argv)
 int	argc;
 char	*argv[];

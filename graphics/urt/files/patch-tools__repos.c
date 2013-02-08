--- tools/repos.c.orig	1992-01-24 01:26:40.000000000 +0900
+++ tools/repos.c	2012-10-15 22:52:09.000000000 +0900
@@ -34,7 +34,7 @@
 
 char buffer[4096];
 
-void
+int
 main(argc, argv)
 int	argc;
 char	*argv[];

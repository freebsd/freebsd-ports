--- tools/rlesetbg.c.orig	1992-01-24 05:44:33.000000000 +0900
+++ tools/rlesetbg.c	2012-10-15 22:59:51.000000000 +0900
@@ -34,7 +34,7 @@
 
 char buffer[4096];
 
-void
+int
 main(argc, argv)
 int	argc;
 char	*argv[];

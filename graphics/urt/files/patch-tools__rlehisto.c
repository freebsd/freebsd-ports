--- tools/rlehisto.c.orig	1992-02-12 06:36:14.000000000 +0900
+++ tools/rlehisto.c	2012-10-15 22:56:16.000000000 +0900
@@ -30,7 +30,7 @@
 
 #define MAXCHAN 10
 
-void
+int
 main(argc, argv)
 int	argc;
 char	*argv[];

--- gbmain.c.orig	1992-08-23 11:37:58.000000000 +0800
+++ gbmain.c	2013-09-26 20:39:56.000000000 +0800
@@ -83,6 +83,7 @@ FILE	*in, *out;
 FILE	*cfont;
 float	H,V;
 
+int
 main (argc,argv)
 int	argc;
 char	**argv;

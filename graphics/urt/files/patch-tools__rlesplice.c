--- tools/rlesplice.c.orig	1992-01-24 05:47:46.000000000 +0900
+++ tools/rlesplice.c	2012-10-16 00:20:54.000000000 +0900
@@ -77,7 +77,7 @@
     }
 }
 
-void
+int
 main(argc, argv)
 int	argc;
 char	*argv[];

--- tools/rleprint.c.orig	1992-08-06 06:39:52.000000000 +0900
+++ tools/rleprint.c	2012-10-15 22:58:20.000000000 +0900
@@ -31,7 +31,7 @@
 
 #define MALLOC_ERR RLE_CHECK_ALLOC( cmd_name( argv ), 0, 0 )
 
-void
+int
 main(argc, argv)
 int	argc;
 char	*argv[];

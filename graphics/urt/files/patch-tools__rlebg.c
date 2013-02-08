--- tools/rlebg.c.orig	1992-04-30 23:11:09.000000000 +0900
+++ tools/rlebg.c	2012-10-15 22:52:09.000000000 +0900
@@ -29,7 +29,7 @@
 #include "rle.h"
 #include "rle_raw.h"
 
-void
+int
 main(argc, argv)
 int	argc;
 char	*argv[];

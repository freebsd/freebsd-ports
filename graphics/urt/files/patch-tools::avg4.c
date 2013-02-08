--- tools/avg4.c.orig	1992-04-30 23:08:43.000000000 +0900
+++ tools/avg4.c	2012-10-15 22:52:09.000000000 +0900
@@ -34,10 +34,10 @@
 #include <stdio.h>
 #include "rle.h"
 
-static bit_count[16] = {0, 63, 63, 127, 63, 127, 127,
+static int bit_count[16] = {0, 63, 63, 127, 63, 127, 127,
     192, 63, 127, 127, 192, 127, 192, 192, 255};
 
-void
+int
 main(argc, argv)
 int	argc;
 char	*argv[];

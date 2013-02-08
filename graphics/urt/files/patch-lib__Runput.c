--- lib/Runput.c.orig	1992-01-29 03:17:40.000000000 +0900
+++ lib/Runput.c	2012-10-15 21:59:43.000000000 +0900
@@ -90,7 +90,8 @@
  * 		    follow the last byte in the run.
  */
 
-#include	"stdio.h"
+#include	<stdio.h>
+#include	<string.h>
 #include	"rle_put.h"
 #include	"rle.h"
 #include	"rle_code.h"

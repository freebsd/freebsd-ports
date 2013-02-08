--- lib/rle_addhist.c.orig	1992-04-30 23:07:45.000000000 +0900
+++ lib/rle_addhist.c	2012-10-15 22:01:16.000000000 +0900
@@ -27,6 +27,7 @@
 
 #include "rle.h"
 #include <stdio.h>
+#include <string.h>
 
 #ifdef	USE_TIME_H
 #include <time.h>

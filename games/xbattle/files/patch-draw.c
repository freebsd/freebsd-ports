--- ./draw.c.orig	1995-12-19 23:21:51.000000000 +0100
+++ ./draw.c	2014-03-29 18:28:41.989953350 +0100
@@ -1,4 +1,5 @@
 #include <stdio.h>
+#include <string.h>
 
 #include "constant.h"
   
@@ -1267,7 +1268,7 @@
 ******************************************************************************/
 
 draw_timer (running_time, player)
-  unsigned long running_time;
+  unsigned int running_time;
   int player;
 {
   char line[MAX_LINE];

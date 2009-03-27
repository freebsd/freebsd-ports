--- pad.c.orig	2009-03-27 17:49:37.000000000 +0100
+++ pad.c	2009-03-27 17:50:01.000000000 +0100
@@ -35,6 +35,7 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <stdio.h>
+#include <stdlib.h>
 
 #define     roundup(x, y)   ((((x)+((y)-1))/(y))*(y))
 

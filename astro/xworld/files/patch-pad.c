--- pad.c.orig	1999-07-28 13:31:27 UTC
+++ pad.c
@@ -35,6 +35,7 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <stdio.h>
+#include <stdlib.h>
 
 #define     roundup(x, y)   ((((x)+((y)-1))/(y))*(y))
 

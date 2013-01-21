--- get/getx11/getx11.h.orig	1994-05-14 10:09:37.000000000 +0900
+++ get/getx11/getx11.h	2012-10-15 22:14:16.000000000 +0900
@@ -27,6 +27,9 @@
  */
 
 #include <stdio.h>
+#include <string.h>
+#include <sys/types.h>
+#include <unistd.h>
 #include <math.h>
 #include <ctype.h>
 #include <X11/X.h>

--- untar.c.old	2010-03-19 22:39:55.000000000 +0100
+++ untar.c	2010-03-19 22:36:01.000000000 +0100
@@ -48,6 +48,9 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+
 #ifndef SEEK_SET
 # define SEEK_SET 0
 #endif

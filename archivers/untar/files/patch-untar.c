--- untar.c.orig	2016-07-26 12:43:54 UTC
+++ untar.c
@@ -48,6 +48,9 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+
 #ifndef SEEK_SET
 # define SEEK_SET 0
 #endif

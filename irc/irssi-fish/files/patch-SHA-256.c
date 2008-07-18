--- SHA-256.c.orig	2005-01-16 14:51:34.000000000 -0900
+++ SHA-256.c	2008-07-14 21:34:42.000000000 -0800
@@ -12,6 +12,7 @@
  * */
 
 #include <stdio.h>
+#include <string.h>
 
 typedef struct {
     unsigned int state[8], length, curlen;

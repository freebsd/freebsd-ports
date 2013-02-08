--- cam.c.orig	2012-09-03 00:31:15.000000000 +0200
+++ cam.c	2012-09-03 00:31:42.000000000 +0200
@@ -24,9 +24,10 @@
 
 
 
+#include <stdlib.h>
 #include "cam.h"
 
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
   if (argc == 1)
   {

--- cam.c.orig	1996-04-09 18:17:57 UTC
+++ cam.c
@@ -24,9 +24,10 @@
 
 
 
+#include <stdlib.h>
 #include "cam.h"
 
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
   if (argc == 1)
   {   

--- app/main.c.orig	2014-08-24 15:44:07 UTC
+++ app/main.c
@@ -17,12 +17,16 @@
  */
 #include <config.h>
 
+#include <ieeefp.h>
+
 #include "app_procs.h"
 
 #include "interface.h"
 
 int main(int argc, char *argv[])
 {
+  fpsetmask(0);
+
   app_init(argc, argv);
 
   if (!app_is_interactive())

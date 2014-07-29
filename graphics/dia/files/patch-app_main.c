--- app/main.c.orig	Sun Mar 25 19:05:16 2001
+++ app/main.c	Thu May 17 14:09:02 2001
@@ -19,2 +19,4 @@
 
+#include <ieeefp.h>
+
 #include "geometry.h"
@@ -35,2 +37,4 @@
 {
+  fpsetmask(0);
+
   app_init(argc, argv);

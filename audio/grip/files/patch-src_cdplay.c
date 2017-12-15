--- src/cdplay.c.orig	2017-10-29 05:14:46 UTC
+++ src/cdplay.c
@@ -20,6 +20,7 @@
  * USA
  */
 
+#include <sys/wait.h>
 #include "cdplay.h"
 #include "grip.h"
 #include "config.h"

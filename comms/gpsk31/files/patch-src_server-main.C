--- src/server-main.C.orig	Sun May  8 13:28:03 2005
+++ src/server-main.C	Sun May  8 13:28:18 2005
@@ -19,6 +19,7 @@
  *   thread and from user interface thread (==interface functions)
  */
 
+#include <sys/types.h>
 #include <sys/mman.h>
 #include "config.h"
 #include <stdio.h>

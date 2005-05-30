--- server/server-main.C.orig	Mon May  2 23:53:42 2005
+++ server/server-main.C	Mon May  2 23:53:56 2005
@@ -19,8 +19,6 @@
  *   thread and from user interface thread (==interface functions)
  */
 
-#include <sys/mman.h>
-
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>

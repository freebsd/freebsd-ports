--- ./lib/config/xnconfig_memory.c.orig	Mon Jun 11 12:08:15 2007
+++ ./lib/config/xnconfig_memory.c	Mon Jun 11 12:08:29 2007
@@ -17,6 +17,7 @@
  *
  */
 
+#include <sys/_types.h>
 #include <sys/shm.h>
 #include <string.h>
 

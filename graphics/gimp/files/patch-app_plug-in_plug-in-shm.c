--- app/plug-in/plug-in-shm.c.orig	Wed Feb 19 01:40:37 2003
+++ app/plug-in/plug-in-shm.c	Wed Feb 19 01:40:49 2003
@@ -17,6 +17,7 @@
  */
 
 #include "config.h"
+#include <sys/types.h>
 
 #ifdef HAVE_IPC_H
 #include <sys/ipc.h>

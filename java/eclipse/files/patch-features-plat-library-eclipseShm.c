--- features/org.eclipse.platform.launchers/library/eclipseShm.c.orig	Wed Aug  2 11:32:25 2006
+++ features/org.eclipse.platform.launchers/library/eclipseShm.c	Wed Aug  2 11:33:30 2006
@@ -182,11 +182,13 @@
 
 #else /* Unix like platforms */
 
+#include <machine/param.h>
+#include <sys/types.h>
+#include <sys/ipc.h>
 #include <sys/shm.h>
 #include <string.h>
 #include <stdlib.h>
 #include <stdio.h>
-#include <sys/types.h>
 #include <unistd.h>
 
 int createSharedData(char** id, int size) {

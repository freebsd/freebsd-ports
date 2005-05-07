--- features/org.eclipse.launchers/library/eclipseShm.c.orig	Fri Apr  1 13:55:58 2005
+++ features/org.eclipse.launchers/library/eclipseShm.c	Sun Apr  3 11:34:02 2005
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

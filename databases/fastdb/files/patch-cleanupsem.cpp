--- cleanupsem.cpp.orig	Thu Aug 12 02:04:05 2004
+++ cleanupsem.cpp	Thu Aug 12 02:04:26 2004
@@ -11,6 +11,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 #include <sys/ipc.h>
 #include <sys/sem.h>
 #include <sys/shm.h>

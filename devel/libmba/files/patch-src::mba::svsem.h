--- src/mba/svsem.h.orig	Wed May 26 16:32:35 2004
+++ src/mba/svsem.h	Mon Feb 21 00:31:21 2005
@@ -9,6 +9,8 @@
 #endif
 
 #include <fcntl.h>
+#include <sys/types.h>
+#include <sys/ipc.h>
 #include <sys/sem.h>
 #include <mba/pool.h>
 #include <mba/varray.h>

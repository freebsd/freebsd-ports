--- src/connection.c.ori	Sat Jan 25 00:33:14 2003
+++ src/connection.c	Sat Jan 25 00:33:38 2003
@@ -30,7 +30,12 @@
 #include <assert.h>
 #include <pthread.h>
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/mount.h>
+#else
 #include <sys/vfs.h>
+#endif
 
 #include "connection.h"
 #include "misc.h"

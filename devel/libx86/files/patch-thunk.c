--- thunk.c	2008-04-02 20:48:00.000000000 -0400
+++ thunk.c	2008-12-03 19:19:25.000000000 -0500
@@ -11,7 +11,9 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <sys/mman.h>
+#ifndef __FreeBSD__
 #include <sys/io.h>
+#endif
 #include <string.h>
 #include <sys/ipc.h>
 #include <sys/shm.h>

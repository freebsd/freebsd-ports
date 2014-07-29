--- messages.c Thu Aug  3 22:29:37 1995
+++ /home/andy/tmp/wrk/messages.c      Wed Dec  2 21:03:17 1998
@@ -3,7 +3,11 @@
 #include <sys/time.h>
 #include <sys/resource.h>
 #include <string.h>
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 #include <memory.h>
 #include <sys/types.h>
 #include <netinet/in.h>

--- client.c   Thu Aug  3 22:29:37 1995
+++ /home/andy/tmp/wrk/client.c        Wed Dec  2 21:05:02 1998
@@ -5,7 +5,11 @@
 #include <stdlib.h>
 #include <netdb.h>
 #include <stdio.h>
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 #include <string.h>
 #include <unistd.h>
 #include <signal.h>

--- server.c   Thu Aug  3 22:29:37 1995
+++ /home/andy/tmp/wrk/server.c        Wed Dec  2 21:04:18 1998
@@ -9,7 +9,11 @@
 #include <math.h>
 #include <memory.h>
 #include <signal.h>
+#ifdef __FreeBSD__
+#include <limits.h>
+#else
 #include <values.h>
+#endif
 
 #include "messages.h"
 #include "creation.h"

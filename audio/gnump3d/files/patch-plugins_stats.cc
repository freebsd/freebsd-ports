--- plugins/stats.cc.orig	Fri Nov 29 04:33:21 2002
+++ plugins/stats.cc	Mon Dec  2 19:32:09 2002
@@ -39,6 +39,11 @@
 #include <stdlib.h>
 
 
+#ifdef HAVE_PTHREAD 
+# include <pthread.h>
+#endif
+
+
 #include "debug.h"
 #include "request.h"
 #include "settings.h"

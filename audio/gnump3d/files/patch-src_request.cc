--- src/request.cc.orig	Fri Nov 29 04:33:21 2002
+++ src/request.cc	Mon Dec  2 19:25:06 2002
@@ -54,6 +54,10 @@
 # include <unistd.h>
 #endif /* HAVE_UNISTD_H */
 
+#ifdef HAVE_PTHREAD
+# include <pthread.h>
+#endif
+
 
 #include "base64.h"
 #include "debug.h"

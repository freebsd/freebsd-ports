--- plugins/bug.cc.orig	Fri Nov 29 04:33:21 2002
+++ plugins/bug.cc	Mon Dec  2 19:27:02 2002
@@ -40,6 +40,11 @@
 #include <sys/utsname.h>
 
 
+#ifdef HAVE_PTHREAD
+# include <pthread.h>
+#endif
+
+
 #include "debug.h"
 #include "iplugin.h"
 #include "request.h"

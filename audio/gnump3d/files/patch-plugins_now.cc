--- plugins/now.cc.orig	Fri Nov 29 04:33:21 2002
+++ plugins/now.cc	Mon Dec  2 19:30:10 2002
@@ -40,6 +40,11 @@
 #include <fstream.h>
 
 
+#ifdef HAVE_PTHREAD
+# include <pthread.h>
+#endif
+
+
 #include "debug.h"
 #include "iplugin.h"
 #include "files.h"

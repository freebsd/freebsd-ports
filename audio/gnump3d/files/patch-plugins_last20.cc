--- plugins/last20.cc.orig	Fri Nov 29 04:33:21 2002
+++ plugins/last20.cc	Mon Dec  2 19:29:11 2002
@@ -40,6 +40,11 @@
 #include <fstream.h>
 
 
+#ifdef HAVE_PTHREAD
+# include <pthread.h>
+#endif
+
+
 #include "debug.h"
 #include "files.h"
 #include "iplugin.h"

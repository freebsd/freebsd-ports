--- plugins/version.cc.orig	Fri Nov 29 04:33:21 2002
+++ plugins/version.cc	Mon Dec  2 19:36:44 2002
@@ -38,6 +38,12 @@
 #include <stdio.h>
 #include <stdlib.h>
 
+
+#ifdef HAVE_PTHREAD 
+# include <pthread.h>
+#endif
+
+
 #include "debug.h"
 #include "iplugin.h"
 #include "plugin.h"

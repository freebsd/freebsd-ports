--- plugins/playlist.cc.orig	Fri Nov 29 04:33:21 2002
+++ plugins/playlist.cc	Mon Dec  2 19:35:39 2002
@@ -39,6 +39,12 @@
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
 #include "files.h"

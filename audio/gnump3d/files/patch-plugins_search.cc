--- plugins/search.cc.orig	Fri Nov 29 04:33:21 2002
+++ plugins/search.cc	Mon Dec  2 19:31:03 2002
@@ -38,6 +38,12 @@
 #include <stdio.h>
 #include <stdlib.h>
 
+
+#ifdef HAVE_PTHREAD 
+# include <pthread.h>
+#endif
+
+
 #include "files.h"
 #include "debug.h"
 #include "dirs.h"

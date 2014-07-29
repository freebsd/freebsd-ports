--- dis/server/sites.c~	Sat Nov 24 14:46:24 2001
+++ dis/server/sites.c	Sat Nov 24 14:46:03 2001
@@ -27,7 +27,11 @@
  *   README file.
  */
 #include <server.h>
+#ifdef HAVE_STDLIB_H
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 #include <string.h>
 #ifdef HAVE_NDBM
 #include <ndbm.h>

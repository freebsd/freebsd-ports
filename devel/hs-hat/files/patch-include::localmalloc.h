--- include/localmalloc.h.orig	Sun Mar 17 21:18:36 2002
+++ include/localmalloc.h	Sun Mar 17 21:18:55 2002
@@ -1,5 +1,5 @@
 #if defined(__APPLE__)
 #include <sys/malloc.h>
 #else
-#include <malloc.h>
+#include <stdlib.h>
 #endif

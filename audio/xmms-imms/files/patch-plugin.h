--- plugin.h.orig	Thu Apr 15 16:15:24 2004
+++ plugin.h	Sat Aug 14 11:08:55 2004
@@ -1,7 +1,11 @@
 #ifndef __PLUGIN_H
 #define __PLUGIN_H
 
+#ifdef HAVE_STDIN
 #include <stdint.h>
+#else
+#include <sys/types.h>
+#endif
 #include "immsconf.h"
 
 #ifdef __cplusplus

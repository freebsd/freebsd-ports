--- plugin.h.orig	Wed Feb 11 17:44:30 2004
+++ plugin.h	Wed Feb 11 17:45:06 2004
@@ -1,7 +1,11 @@
 #ifndef __PLUGIN_H
 #define __PLUGIN_H
 
+#if HAVE_STDINT_H
 #include <stdint.h>
+#else
+#include <sys/types.h>
+#endif
 
 #ifdef __cplusplus
 extern "C" {

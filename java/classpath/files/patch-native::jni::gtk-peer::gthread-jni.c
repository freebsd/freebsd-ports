--- native/jni/gtk-peer/gthread-jni.c.orig	Mon Oct 25 15:42:21 2004
+++ native/jni/gtk-peer/gthread-jni.c	Mon Oct 25 15:45:31 2004
@@ -218,7 +218,11 @@
 /* Global data				     				*/
 /************************************************************************/
 
+#if __FreeBSD_version < 500000
+#include <inttypes.h>
+#else
 #include <stdint.h>		/* provides intptr_t */
+#endif
 #include <stdarg.h>		/* va_list */
 #include "gthread-jni.h"
 #include <assert.h>		/* assert() */

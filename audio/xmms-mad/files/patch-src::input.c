--- src/input.c.orig	Sat Aug 31 02:39:43 2002
+++ src/input.c	Sat Aug 31 02:41:14 2002
@@ -20,6 +20,10 @@
  */
 #include "config.h"
 
+#ifdef HAVE_SYS_TYPES_H 
+#include <sys/types.h>
+#endif /* HAVE_SYS_TYPES_H */
+
 #ifdef HAVE_ASSERT_H
 #include <assert.h>
 #endif /* HAVE_ASSERT_H */

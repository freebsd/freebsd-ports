--- lib/select.c.orig	Tue Dec 21 09:06:14 2004
+++ lib/select.c	Tue Dec 21 09:06:27 2004
@@ -23,11 +23,11 @@
 
 #include "setup.h"
 
-#ifdef HAVE_SYS_SELECT_H
-#include <sys/select.h>
-#endif
 #ifdef HAVE_SYS_TYPES_H
 #include <sys/types.h>
+#endif
+#ifdef HAVE_SYS_SELECT_H
+#include <sys/select.h>
 #endif
 
 #ifdef HAVE_SYS_TIME_H

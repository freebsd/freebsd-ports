--- taxipilot/timemanager.h.orig	Wed Aug 21 11:20:40 2002
+++ taxipilot/timemanager.h	Thu Nov 20 19:19:09 2003
@@ -19,7 +19,12 @@
 #define TIMEMANAGER_H
 
 #include <qobject.h>
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#else
+#include <sys/types.h>
+#define int_fast32_t int32_t
+#endif
 #include <qlist.h>
 
 #include "timedobject.h"

--- src/command.h.orig	Wed May 25 16:51:55 2005
+++ src/command.h	Wed May 25 16:52:21 2005
@@ -70,6 +70,8 @@
 #include <X11/X.h>                      
 #endif
 
+#include <sys/select.h>
+
 #include "types.h"			/* Various typedef */
 #include "error.h"			/* Error wrapper */
 #include "vector.h"                     /* Vector API */

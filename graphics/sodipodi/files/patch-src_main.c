--- src/main.c.orig	Thu May 30 10:26:44 2002
+++ src/main.c	Thu May 30 10:29:17 2002
@@ -17,7 +17,7 @@
 #include <tree.h> /* libxml */
 
 #ifdef __FreeBSD__
-#include <floatingpoint.h>
+#include <ieeefp.h>
 #endif
 
 #include "sodipodi-private.h"

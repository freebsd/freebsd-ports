--- common/soi.c.orig	2011-05-07 15:36:36.000000000 -0500
+++ common/soi.c	2012-03-10 17:08:47.000000000 -0500
@@ -15,7 +15,7 @@
 #include <string.h>
 #ifdef __APPLE__
 #include <malloc/malloc.h>
-#else
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
 #include "port.h"

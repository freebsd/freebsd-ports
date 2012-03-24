--- common/soi1.c.orig	2011-05-07 15:36:50.000000000 -0500
+++ common/soi1.c	2012-03-10 17:10:37.000000000 -0500
@@ -15,7 +15,7 @@
 #include <string.h>
 #ifdef __APPLE__
 #include <malloc/malloc.h>
-#else
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
 #include "port.h"

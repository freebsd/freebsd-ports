--- common/soi1.c.orig	2014-05-03 13:12:35 UTC
+++ common/soi1.c
@@ -15,7 +15,7 @@
 #include <string.h>
 #ifdef __APPLE__
 #include <malloc/malloc.h>
-#else
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
 #include "port.h"

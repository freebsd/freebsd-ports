--- ZODB/TimeStamp.c.orig	Wed Sep 20 03:00:08 2000
+++ ZODB/TimeStamp.c	Tue Sep 18 14:56:25 2001
@@ -91,7 +91,7 @@
 #include <stdlib.h>
 #include <time.h>
 #ifdef USE_EXTENSION_CLASS
-#include "ExtensionClass/ExtensionClass.h"
+#include "../ExtensionClass/src/ExtensionClass.h"
 #else
 #include "Python.h"
 #endif

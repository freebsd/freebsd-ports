--- ajax/core/ajfileio.c.orig	2023-12-02 19:03:54 UTC
+++ ajax/core/ajfileio.c
@@ -31,6 +31,7 @@
 #include "ajfileio.h"
 #include "ajutil.h"
 #include "ajfile.h"
+#include "ajsys.h"
 
 #include <string.h>
 #include <errno.h>

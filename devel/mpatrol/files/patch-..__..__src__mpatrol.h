
$FreeBSD$

--- ../../src/mpatrol.h
+++ ../../src/mpatrol.h
@@ -32,6 +32,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <stdarg.h>
+#include <unistd.h>
 #if !MP_NOCPLUSPLUS
 #ifdef __cplusplus
 #include <new>

--- libmpio/debug.h.orig       Thu Jun 19 19:47:19 2003
+++ libmpio/debug.h    Thu Jun 19 19:47:39 2003
@@ -27,7 +27,7 @@
 #ifdef sun
 #include <sys/int_types.h>
 #else
-#include <stdint.h>
+#include <sys/types.h>
 #endif

 #ifdef __cplusplus

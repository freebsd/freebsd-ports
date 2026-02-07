- workaround for https://github.com/adrian-thurston/colm/issues/152

--- src/bytecode.c.orig	2022-08-23 18:33:46 UTC
+++ src/bytecode.c
@@ -20,6 +20,8 @@
  * SOFTWARE.
  */
 
+#include "config.h"
+
 #include <colm/bytecode.h>
 
 #include <sys/types.h>

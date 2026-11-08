--- src/libscotch/common_thread_system.c.orig	2023-08-15 14:47:40 UTC
+++ src/libscotch/common_thread_system.c
@@ -51,6 +51,8 @@
 **  The defines and includes.
 */
 
+#include <unistd.h>
+
 #include "module.h"
 #include "common.h"
 #include "common_thread_system.h"

--- src/handle_dep.cc.orig	2021-10-23 10:18:49 UTC
+++ src/handle_dep.cc
@@ -1,3 +1,5 @@
+#include <sys/types.h>
+#include <sys/wait.h>
 #include "handle_dep.h"
 #include "printutils.h"
 #include <string>

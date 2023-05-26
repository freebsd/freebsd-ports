--- src/main/tools/process-tools-linux.cc.orig	1979-12-31 23:00:00 UTC
+++ src/main/tools/process-tools-linux.cc
@@ -17,6 +17,7 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <unistd.h>
+#include <signal.h>
 
 #include "src/main/tools/process-tools.h"
 

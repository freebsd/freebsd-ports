--- src/main/tools/process-tools-linux.cc.orig	2020-06-02 21:33:22.556035000 +0200
+++ src/main/tools/process-tools-linux.cc	2020-06-02 21:34:05.346824000 +0200
@@ -17,6 +17,7 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <unistd.h>
+#include <signal.h>
 
 #include "src/main/tools/process-tools.h"
 

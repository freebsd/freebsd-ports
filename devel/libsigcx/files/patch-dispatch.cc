--- sigcx/dispatch.cc.orig	Sun Apr 13 15:52:19 2003
+++ sigcx/dispatch.cc	Sun Apr 13 15:52:26 2003
@@ -18,6 +18,9 @@
 #include <stdexcept>
 
 #include <signal.h>
+#include <sys/types.h>
+#include <sys/times.h>
+#include <unistd.h>
 
 #include "sigcx/dispatch.h"
 

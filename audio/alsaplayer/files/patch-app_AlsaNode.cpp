--- app/AlsaNode.cpp.orig	Sun Jun 29 20:14:02 2003
+++ app/AlsaNode.cpp	Sun Jun 29 20:14:10 2003
@@ -23,8 +23,8 @@
 #include "AlsaPlayer.h"
 #include "config.h"
 #include "prefs.h"
-#include <sys/mman.h>
 #include <sys/types.h>
+#include <sys/mman.h>
 #include <sys/stat.h>
 #ifdef USE_REALTIME
 #include <sched.h>

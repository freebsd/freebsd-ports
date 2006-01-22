--- modules/src/frboutmodule/x11output.c.orig
+++ modules/src/frboutmodule/x11output.c
@@ -27,7 +27,8 @@
 #include <math.h> // for fabs
 #include <string.h>
 
-#include <sys/ipc.h>
+//#include <sys/ipc.h>
+#include <sys/types.h>
 #include <sys/shm.h>
 
 #include "outputdriver.h"

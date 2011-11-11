--- src/lib/fcitx/instance-internal.h~	2011-10-02 05:43:11.000000000 -0500
+++ src/lib/fcitx/instance-internal.h	2011-11-09 04:34:08.305040197 -0600
@@ -26,6 +26,8 @@
 #define _FCITX_INSTANCE_INTERNAL_H_
 
 #include <semaphore.h>
+#include <sys/select.h>
+#include <pthread.h>
 
 #include "fcitx-utils/utarray.h"
 #include "configfile.h"

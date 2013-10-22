--- src/Misc/Master.h~	2013-10-22 18:41:37.000000000 +0300
+++ src/Misc/Master.h	2013-10-22 18:41:53.000000000 +0300
@@ -33,6 +33,8 @@
 
 #include "../Params/Controller.h"
 
+#include <pthread.h>
+
 typedef enum {
     MUTEX_TRYLOCK, MUTEX_LOCK, MUTEX_UNLOCK
 } lockset;

--- src/Misc/Master.h.orig	2012-06-16 04:02:12 UTC
+++ src/Misc/Master.h
@@ -33,6 +33,8 @@
 
 #include "../Params/Controller.h"
 
+#include <pthread.h>
+
 typedef enum {
     MUTEX_TRYLOCK, MUTEX_LOCK, MUTEX_UNLOCK
 } lockset;

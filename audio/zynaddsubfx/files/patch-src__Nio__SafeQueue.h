--- src/Nio/SafeQueue.h~	2013-10-22 18:37:27.000000000 +0300
+++ src/Nio/SafeQueue.h	2013-10-22 18:37:34.000000000 +0300
@@ -2,6 +2,7 @@
 #ifndef SAFEQUEUE_H
 #define SAFEQUEUE_H
 #include <cstdlib>
+#include <pthread.h>
 #include <semaphore.h>
 
 /**

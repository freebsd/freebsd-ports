--- src/Nio/SafeQueue.h.orig	2011-12-19 21:14:30 UTC
+++ src/Nio/SafeQueue.h
@@ -2,6 +2,7 @@
 #ifndef SAFEQUEUE_H
 #define SAFEQUEUE_H
 #include <cstdlib>
+#include <pthread.h>
 #include <semaphore.h>
 
 /**

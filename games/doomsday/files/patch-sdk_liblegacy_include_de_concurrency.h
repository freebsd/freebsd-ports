--- sdk/liblegacy/include/de/concurrency.h.orig	2020-08-27 20:47:27 UTC
+++ sdk/liblegacy/include/de/concurrency.h
@@ -31,7 +31,7 @@
 
 typedef void *thread_t;
 typedef void *mutex_t;
-typedef void *sem_t;
+//typedef void *sem_t;
 
 typedef enum systhreadexitstatus_e {
     DENG_THREAD_STOPPED_NORMALLY,

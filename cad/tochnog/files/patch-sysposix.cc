--- sysposix.cc.orig
+++ sysposix.cc
@@ -20,20 +20,20 @@
 #include "tochnog.h"
 #include "pthread.h"
 
-pthread_mutex_t mutex;
+pthread_mutex_t mtx;
 long int inext=0;
 pthread_t threads[MTHREAD];
 
 void parallel_sys_initialize( void )
 
 {
-  pthread_mutex_init( &mutex, NULL );
+  pthread_mutex_init( &mtx, NULL );
 }
 
 void parallel_sys_lock( void )
 
 {
-  pthread_mutex_lock( &mutex );
+  pthread_mutex_lock( &mtx );
 }
 
 void parallel_sys_next_of_loop( long int next_of_loop[], long int max_loop,
@@ -96,5 +96,5 @@
 void parallel_sys_unlock( void )
 
 {
-  pthread_mutex_unlock( &mutex );
+  pthread_mutex_unlock( &mtx );
 }

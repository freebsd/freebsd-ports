--- tools/fusion_bench.c
+++ tools/fusion_bench.c
@@ -336,7 +336,11 @@ static void
 bench_mutex_threaded( void )
 {
      int             i;
+#if HAVE_DECL_PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
      pthread_mutex_t lock = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
+#else
+     pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
+#endif
 
 
      /* mutex lock/unlock (2-5 threads) */
@@ -367,7 +371,11 @@ static void
 bench_mutex( void )
 {
      pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
+#if HAVE_DECL_PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
      pthread_mutex_t rmutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
+#else
+     pthread_mutex_t rmutex = PTHREAD_MUTEX_INITIALIZER;
+#endif
 
 
      /* pthread_mutex lock/unlock */

--- ../../deploy/src/plugin/oji-plugin/include/solaris/navig4/nspr/md/_pth.h	22 Oct 2003 23:04:19 -0000	1.1.1.1
+++ ../../deploy/src/plugin/oji-plugin/include/solaris/navig4/nspr/md/_pth.h	21 Oct 2004 05:47:13 -0000
@@ -52,7 +52,7 @@
 #define PTHREAD_MUTEXATTR_INIT        pthread_mutexattr_init
 #define PTHREAD_MUTEXATTR_DESTROY     pthread_mutexattr_destroy
 #define PTHREAD_MUTEX_INIT(m, a)      pthread_mutex_init(&(m), &(a))
-#define PTHREAD_MUTEX_IS_LOCKED(m)    (EBUSY == pthread_mutex_trylock(&(m)))
+#define PTHREAD_MUTEX_IS_LOCKED(m)    (0 != pthread_mutex_trylock(&(m)))
 #define PTHREAD_CONDATTR_INIT         pthread_condattr_init
 #define PTHREAD_CONDATTR_DESTROY      pthread_condattr_destroy
 #define PTHREAD_COND_INIT(m, a)       pthread_cond_init(&(m), &(a))

--- ../pr/include/md/_pth.h.orig	Mon Jul 26 07:23:42 2004
+++ ../pr/include/md/_pth.h	Mon Jul 26 07:18:37 2004
@@ -90,7 +90,7 @@
 #define _PT_PTHREAD_MUTEXATTR_INIT        pthread_mutexattr_init
 #define _PT_PTHREAD_MUTEXATTR_DESTROY     pthread_mutexattr_destroy
 #define _PT_PTHREAD_MUTEX_INIT(m, a)      pthread_mutex_init(&(m), &(a))
-#define _PT_PTHREAD_MUTEX_IS_LOCKED(m)    (EBUSY == pthread_mutex_trylock(&(m)))
+#define _PT_PTHREAD_MUTEX_IS_LOCKED(m)    (0 != pthread_mutex_trylock(&(m)))
 #if defined(DARWIN)
 #define _PT_PTHREAD_CONDATTR_INIT(x)      0
 #else

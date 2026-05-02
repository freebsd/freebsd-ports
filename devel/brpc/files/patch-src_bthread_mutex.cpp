--- src/bthread/mutex.cpp.orig	2026-02-23 02:11:29 UTC
+++ src/bthread/mutex.cpp
@@ -477,6 +477,12 @@ static void init_sys_mutex_lock() {
     sys_pthread_mutex_lock = (MutexOp)dlsym(RTLD_NEXT, "pthread_mutex_lock");
     sys_pthread_mutex_trylock = (MutexOp)dlsym(RTLD_NEXT, "pthread_mutex_trylock");
     sys_pthread_mutex_unlock = (MutexOp)dlsym(RTLD_NEXT, "pthread_mutex_unlock");
+#elif defined(OS_FREEBSD)
+    sys_pthread_mutex_init = (MutexInitOp)dlsym(RTLD_NEXT, "pthread_mutex_init");
+    sys_pthread_mutex_destroy = (MutexOp)dlsym(RTLD_NEXT, "pthread_mutex_destroy");
+    sys_pthread_mutex_lock = (MutexOp)dlsym(RTLD_NEXT, "pthread_mutex_lock");
+    sys_pthread_mutex_trylock = (MutexOp)dlsym(RTLD_NEXT, "pthread_mutex_trylock");
+    sys_pthread_mutex_unlock = (MutexOp)dlsym(RTLD_NEXT, "pthread_mutex_unlock");
 #endif
 }
 

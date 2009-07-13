--- common/source/linux/MDispatcher.cc.orig	2008-09-25 08:24:31.000000000 +0000
+++ common/source/linux/MDispatcher.cc	2008-09-25 08:25:09.000000000 +0000
@@ -21,8 +21,8 @@
 #include <unistd.h>
 #include <mysql.h>
 
-#define MX_LOCK(mx) { if (0) g_message("[%i]:%s: LOCK %s", (int)pthread_self(), __FUNCTION__, #mx); pthread_mutex_lock(mx); }
-#define MX_UNLOCK(mx) { if (0) g_message("[%i]:%s: UNLOCK %s", (int)pthread_self(), __FUNCTION__, #mx); pthread_mutex_unlock(mx); }
+#define MX_LOCK(mx) { if (0) g_message("[%lu]:%s: LOCK %s", (unsigned long)pthread_self(), __FUNCTION__, #mx); pthread_mutex_lock(mx); }
+#define MX_UNLOCK(mx) { if (0) g_message("[%lu]:%s: UNLOCK %s", (unsigned long)pthread_self(), __FUNCTION__, #mx); pthread_mutex_unlock(mx); }
 
 
 void *MDispatcher::thread_func(Fetcher *self)

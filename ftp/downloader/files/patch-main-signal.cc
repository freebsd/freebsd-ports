--- main/signal.cc.bak	Fri Jul  2 00:41:31 2004
+++ main/signal.cc	Fri Sep 16 22:58:09 2005
@@ -120,7 +120,7 @@
 	pthread_mutexattr_t ma;
 	pthread_mutexattr_init(&ma);
 #if !defined (__sparc__) && !defined(__mips__)
-	pthread_mutexattr_settype(&ma,MUTEX_TYPE_FAST);
+	pthread_mutexattr_settype(&ma,PTHREAD_MUTEX_NORMAL);
 #elif defined(__mips__)
 	pthread_mutexattr_settype(&ma,MUTEX_TYPE_NORMAL);	
 #endif

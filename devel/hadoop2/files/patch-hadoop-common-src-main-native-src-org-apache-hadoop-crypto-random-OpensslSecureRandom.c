See https://issues.apache.org/jira/browse/HADOOP-11638
--- hadoop-common-project/hadoop-common/src/main/native/src/org/apache/hadoop/crypto/random/OpensslSecureRandom.c.orig	2015-03-05 16:47:38.000000000 +0300
+++ hadoop-common-project/hadoop-common/src/main/native/src/org/apache/hadoop/crypto/random/OpensslSecureRandom.c	2015-03-05 16:48:34.000000000 +0300
@@ -27,6 +27,10 @@
 #include <unistd.h>
 #include <sys/syscall.h>
 #include <sys/types.h>
+
+#if defined(__FreeBSD__)
+#include <pthread_np.h>
+#endif
 #endif
 
 #ifdef WINDOWS
@@ -274,7 +278,9 @@ static void pthreads_locking_callback(in
 
 static unsigned long pthreads_thread_id(void)
 {
-  return (unsigned long)syscall(SYS_gettid);
+unsigned long thread_id = 0;
+thread_id = (unsigned long)pthread_getthreadid_np();
+return thread_id;
 }
 
 #endif /* UNIX */

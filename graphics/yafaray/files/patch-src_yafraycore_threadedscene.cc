--- src/yafraycore/threadedscene.cc.orig	Mon Jul  4 11:01:46 2005
+++ src/yafraycore/threadedscene.cc	Sat Sep 23 00:16:35 2006
@@ -35,6 +35,10 @@
 #include <semaphore.h>
 #include<map>
 
+#ifdef __FreeBSD__
+#include<sys/time.h>
+#endif
+
 sem_t pstop;
 
 

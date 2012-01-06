--- ./src/ha_pinba.cc.orig	2011-07-26 18:52:53.000000000 +0400
+++ ./src/ha_pinba.cc	2011-08-27 18:58:00.000000000 +0400
@@ -45,6 +45,10 @@
 
 #include "ha_pinba.h"
 
+#ifdef PINBA_ENGINE_HAVE_PTHREAD_SETAFFINITY_NP
+#include <pthread_np.h>
+#endif
+
 #ifdef PINBA_ENGINE_MYSQL_VERSION_5_5
 # define pinba_free(a, b) my_free(a)
 #else
@@ -427,13 +431,13 @@
 		unsigned long mask;
 
 		mask = 1;
-		pthread_setaffinity_np(collector_thread, sizeof(mask), (cpu_set_t *)&mask);
+		pthread_setaffinity_np(collector_thread, sizeof(mask), (cpuset_t *)&mask);
 		
 		mask = 2;
-		pthread_setaffinity_np(data_thread, sizeof(mask), (cpu_set_t *)&mask);
+		pthread_setaffinity_np(data_thread, sizeof(mask), (cpuset_t *)&mask);
 		
 		mask = 4;
-		pthread_setaffinity_np(stats_thread, sizeof(mask), (cpu_set_t *)&mask);
+		pthread_setaffinity_np(stats_thread, sizeof(mask), (cpuset_t *)&mask);
 #endif
 	}
 
@@ -452,6 +456,7 @@
 	int error = 0;
 	DBUG_ENTER("pinba_engine_shutdown");
 
+	pthread_detach(collector_thread);
 	pthread_cancel(collector_thread);
 	pthread_join(collector_thread, NULL);
 

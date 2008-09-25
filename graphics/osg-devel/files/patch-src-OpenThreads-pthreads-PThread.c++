--- src/OpenThreads/pthreads/PThread.c++.orig	2008-09-25 18:28:42.000000000 +0400
+++ src/OpenThreads/pthreads/PThread.c++	2008-09-25 18:52:13.000000000 +0400
@@ -21,6 +21,7 @@
 #include <sys/types.h>
 #include <unistd.h>
 #include <pthread.h>
+#include <pthread_np.h>
 
 #if defined __linux || defined __sun || defined __APPLE__
 #include <string.h>

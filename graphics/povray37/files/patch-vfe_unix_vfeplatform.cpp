--- vfe/unix/vfeplatform.cpp.orig	2011-01-02 14:43:05.000000000 +0100
+++ vfe/unix/vfeplatform.cpp	2011-03-08 12:57:50.000000000 +0100
@@ -97,6 +97,7 @@
 #include <pthread.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/wait.h>
 
 #ifdef HAVE_TIME_H
 # include <time.h>

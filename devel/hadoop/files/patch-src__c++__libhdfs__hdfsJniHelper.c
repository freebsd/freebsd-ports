--- src/c++/libhdfs/hdfsJniHelper.c.orig	2011-05-04 08:30:16.000000000 +0200
+++ src/c++/libhdfs/hdfsJniHelper.c	2011-08-07 16:40:54.000000000 +0200
@@ -15,7 +15,7 @@
  */
 
 #include <string.h> 
-#include <error.h>
+//#include <error.h>
 #include "hdfsJniHelper.h"
 
 static pthread_mutex_t hdfsHashMutex = PTHREAD_MUTEX_INITIALIZER;

--- common/drivers/posix/mutex_lock_pthreads.h.orig	Tue Oct 28 12:21:45 2003
+++ common/drivers/posix/mutex_lock_pthreads.h	Thu Oct 30 00:30:26 2003
@@ -37,6 +37,7 @@
 
 #include "os/mutex_lock.h"
 #include <pthread.h>
+#include <errno.h>
 
 /**
   *@author Juan Linietsky

--- uthread_spinlock.c.orig	Thu Aug 18 13:45:38 2005
+++ uthread_spinlock.c	Thu Aug 18 13:44:36 2005
@@ -33,10 +33,10 @@
  *
  */
 
+#include <pthread.h>
 #include <stdio.h>
 #include <sched.h>
 #include <unistd.h>
-#include <pthread.h>
 #include <string.h>
 #include "spinlock.h"
 

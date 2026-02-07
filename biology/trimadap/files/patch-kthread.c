--- kthread.c.orig	2017-02-11 22:31:35 UTC
+++ kthread.c
@@ -1,6 +1,7 @@
 #include <pthread.h>
 #include <stdlib.h>
 #include <limits.h>
+#include <inttypes.h>
 
 /************
  * kt_for() *

--- kthread.c.orig	2021-08-22 22:59:48 UTC
+++ kthread.c
@@ -1,6 +1,7 @@
 #include <pthread.h>
 #include <stdlib.h>
 #include <limits.h>
+#include <inttypes.h>
 
 /************
  * kt_for() *

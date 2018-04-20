--- SeqLib/bwa/kthread.c.orig	2018-03-23 18:48:35 UTC
+++ SeqLib/bwa/kthread.c
@@ -1,6 +1,7 @@
 #include <pthread.h>
 #include <stdlib.h>
 #include <limits.h>
+#include <inttypes.h>
 
 /************
  * kt_for() *

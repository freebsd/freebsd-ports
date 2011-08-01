--- tevent_signal.c.orig	2011-07-24 22:04:44.000000000 +0200
+++ tevent_signal.c	2011-07-30 03:36:03.000000000 +0200
@@ -30,7 +30,7 @@
 #include "tevent_internal.h"
 #include "tevent_util.h"
 
-#define TEVENT_NUM_SIGNALS 64
+#define TEVENT_NUM_SIGNALS SIGRTMAX
 
 /* maximum number of SA_SIGINFO signals to hold in the queue.
   NB. This *MUST* be a power of 2, in order for the ring buffer

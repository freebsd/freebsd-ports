--- runtime/flang/async.c.orig	2017-10-19 11:03:03 UTC
+++ runtime/flang/async.c
@@ -39,9 +39,10 @@
 #include <errno.h>
 #endif
 
+#include <sys/signal.h>
+
 #include "stdioInterf.h"
 #include "async.h"
-
 
 #define FIO_MAX_ASYNC_TRANSACTIONS 16
 

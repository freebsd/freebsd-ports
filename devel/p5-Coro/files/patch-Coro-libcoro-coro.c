--- Coro/libcoro/coro.c.orig	2015-12-10 10:24:21 UTC
+++ Coro/libcoro/coro.c
@@ -38,6 +38,7 @@
  * go to Ralf S. Engelschall <rse@engelschall.com>.
  */
 
+#include <sys/types.h>
 #include "coro.h"
 
 #include <stddef.h>

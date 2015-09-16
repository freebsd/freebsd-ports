--- Coro/libcoro/coro.c.orig	2012-12-21 04:57:20 UTC
+++ Coro/libcoro/coro.c
@@ -38,6 +38,7 @@
  * go to Ralf S. Engelschall <rse@engelschall.com>.
  */
 
+#include <sys/types.h>
 #include "coro.h"
 
 #include <stddef.h>

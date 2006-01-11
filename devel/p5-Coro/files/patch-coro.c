--- Coro/libcoro/coro.c.orig	Wed Jan 11 13:16:29 2006
+++ Coro/libcoro/coro.c	Wed Jan 11 13:16:57 2006
@@ -30,6 +30,7 @@
  * go to Ralf S. Engelschall <rse@engelschall.com>.
  */
 
+#include <sys/types.h>
 #include "coro.h"
 
 #if !defined(STACK_ADJUST_PTR)

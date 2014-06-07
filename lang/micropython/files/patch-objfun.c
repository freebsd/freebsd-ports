--- ../py/objfun.c.orig	2014-06-04 22:09:47.000000000 +0200
+++ ../py/objfun.c	2014-06-04 22:10:16.000000000 +0200
@@ -27,7 +27,11 @@
 #include <stdbool.h>
 #include <string.h>
 #include <assert.h>
+#ifndef __FreeBSD__
 #include <alloca.h>
+#else
+#include <stdlib.h>
+#endif
 
 #include "mpconfig.h"
 #include "nlr.h"

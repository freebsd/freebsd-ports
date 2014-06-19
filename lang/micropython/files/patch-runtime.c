--- ../py/runtime.c.orig	2014-06-04 22:05:32.000000000 +0200
+++ ../py/runtime.c	2014-06-04 22:06:16.000000000 +0200
@@ -27,7 +27,11 @@
 #include <stdio.h>
 #include <string.h>
 #include <assert.h>
+#ifndef __FreeBSD__
 #include <alloca.h>
+#else
+#include <stdlib.h> /* alloca() */
+#endif
 
 #include "mpconfig.h"
 #include "nlr.h"

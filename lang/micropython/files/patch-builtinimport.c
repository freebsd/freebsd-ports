--- ../py/builtinimport.c.orig	2014-06-05 06:09:16.000000000 +0200
+++ ../py/builtinimport.c	2014-06-05 06:09:56.000000000 +0200
@@ -28,7 +28,11 @@
 #include <stdio.h>
 #include <string.h>
 #include <assert.h>
+#ifndef __FreeBSD__
 #include <alloca.h>
+#else
+#include <stdlib.h>
+#endif
 
 #include "mpconfig.h"
 #include "nlr.h"

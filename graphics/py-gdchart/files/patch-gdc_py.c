--- gdc_py.c.orig	Sat Mar 17 04:06:08 2001
+++ gdc_py.c	Mon Jun 18 17:03:24 2001
@@ -33,6 +33,8 @@
 #include <stdio.h>
 #include <string.h>
 #include <assert.h>
+#include <limits.h>
+#define MAXSHORT SHRT_MAX
 
 #include "Python.h"
 #include "cStringIO.h"

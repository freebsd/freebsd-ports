--- gdc_py.c.orig	Mon Feb 25 19:36:07 2002
+++ gdc_py.c	Thu Jul 18 14:52:48 2002
@@ -26,6 +26,9 @@
 #include <stdio.h>
 #include <string.h>
 #include <assert.h>
+#include <limits.h>
+#define MAXSHORT SHRT_MAX
+#define HAVE_JPEG 1
 
 #include "Python.h"
 #include "cStringIO.h"

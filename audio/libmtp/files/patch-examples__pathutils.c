--- ./examples/pathutils.c.orig	2008-05-03 03:17:02.000000000 +0400
+++ ./examples/pathutils.c	2009-01-14 01:12:55.000000000 +0300
@@ -21,6 +21,8 @@
  */
 #include "common.h"
 #include "pathutils.h"
+#include <stdlib.h>
+#include <limits.h>
 #include <string.h>
 #include <libgen.h>
 

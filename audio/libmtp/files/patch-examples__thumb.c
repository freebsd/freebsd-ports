--- ./examples/thumb.c.orig	2007-11-11 03:06:28.000000000 +0300
+++ ./examples/thumb.c	2009-01-14 01:12:55.000000000 +0300
@@ -22,6 +22,8 @@
  */
 #include "common.h"
 #include "string.h"
+#include <stdlib.h>
+#include <limits.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <errno.h>

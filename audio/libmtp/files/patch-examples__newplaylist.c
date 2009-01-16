--- ./examples/newplaylist.c.orig	2008-06-23 01:44:46.000000000 +0400
+++ ./examples/newplaylist.c	2009-01-14 01:12:55.000000000 +0300
@@ -21,6 +21,7 @@
  */
 #include "common.h"
 #include "string.h"
+#include <stdlib.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <errno.h>

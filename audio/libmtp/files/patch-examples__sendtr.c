--- ./examples/sendtr.c.orig	2008-08-17 01:01:09.000000000 +0400
+++ ./examples/sendtr.c	2009-01-14 01:12:55.000000000 +0300
@@ -31,6 +31,8 @@
 
 #include "common.h"
 #include "util.h"
+#include <stdlib.h>
+#include <limits.h>
 #include <string.h>
 #include <libgen.h>
 #include <sys/stat.h>

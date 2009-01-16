--- ./examples/delfile.c.orig	2009-01-14 01:14:19.000000000 +0300
+++ ./examples/delfile.c	2009-01-14 01:15:00.000000000 +0300
@@ -23,6 +23,8 @@
 #include "common.h"
 #include "string.h"
 #include "pathutils.h"
+#include <stdlib.h>
+#include <limits.h>
 
 void delfile_usage(void);
 void delfile_function(char *);
